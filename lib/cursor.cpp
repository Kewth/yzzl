#include <cstdio>
#include "../include/cursor.h"

namespace cursor {
	void up(int times) {
		printf("\033[%dA", times);
	}
	void down(int times) {
		printf("\033[%dB", times);
	}
	void left(int times) {
		printf("\033[%dC", times);
	}
	void right(int times) {
		printf("\033[%dD", times);
	}
	void to_head() {
		printf("\n\033[1A");
	}
	void clear_screen() {
		printf("\033[2J");
	}
	void set_to(int x, int y) {
		printf("\033[%d;%dH", x, y);
	}
};
