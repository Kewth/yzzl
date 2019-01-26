#include <termios.h>
#include <cstdio>
#include <cstring>
#include "input.h"

namespace input {
	int getch() {
		struct termios tm, tm_old;
		int fd = 0, ch;
		if (tcgetattr(fd, &tm) < 0) {//保存现在的终端设置
			return -1;
		}
		tm_old = tm;
		cfmakeraw(&tm);//更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
		if (tcsetattr(fd, TCSANOW, &tm) < 0) {//设置上更改之后的设置
			return -1;
		}
		ch = getchar();
		if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {//更改设置为最初的样子
			return -1;
		}
		return ch;
	}

	bool choose_in_cases(const char *accept_option, const char *denied_option)
	{
		for (; ;) {
			int ch = getch();
			if (strchr(accept_option, ch) != NULL)
				return true;
			if (strchr(denied_option, ch) != NULL)
				return false;
		}
		return true;
	}

	bool chooseyn() {
		return choose_in_cases("Yy", "Nn");
	}
};
