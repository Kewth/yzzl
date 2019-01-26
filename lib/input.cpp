#include <termios.h>
#include <cstdio>
#include "../include/input.h"
#include "../include/ytime.h"

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

	int ifgetch(double time) {
		unsigned long long end = ytime::clock() + time * 1000;
		while(ytime::clock() < end) {
			/* if(kbhit()) */ // 就等着你的 kbhit 了
			/* 	return getch(); */
		}
		return -1;
	}

	bool choose_in_cases(int *accept_option, int accept_option_num,
			int *denied_option, int denied_option_num)
	{
		for (; ;) {
			int ch = getch(), i;
			for (i = 0; i < accept_option_num; ++i)
				if (ch == accept_option[i])
					return true;
			for (i = 0; i < denied_option_num; ++i)
				if (ch == denied_option[i])
					return false;
		}
		return true;
	}

	bool chooseyn() {
		int accept[2] = {'y', 'Y'}, denied[2] = {'n', 'N'};
		return choose_in_cases(accept, 2, denied, 2);
	}
};
