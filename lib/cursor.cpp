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
	void to_haed() {
		printf("\n\033[1A");
	}
};
