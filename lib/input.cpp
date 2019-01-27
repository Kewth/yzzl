#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>
#include <cstring>
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
			if(kbhit())
				return getch();
		}
		return -1;
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

	bool kbhit() {
		struct termios oldt, newt;
		int ch;
		int oldf;
		tcgetattr(STDIN_FILENO, &oldt);
		newt = oldt;
		newt.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
		oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
		fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
		ch = getchar();
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		fcntl(STDIN_FILENO, F_SETFL, oldf);
		if(ch != EOF) {
			ungetc(ch, stdin);
			return 1;
		}
		return 0;
	}

	void clear() {
		// 清空键盘输入
		while(kbhit())
			getch();
	}
};
