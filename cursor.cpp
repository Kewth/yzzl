#include <cstdio>
#include "head_file/cursor.h"

void cursor::up(int times) {
	printf("\033[%dA", times);
}

void cursor::down(int times) {
	printf("\033[%dB", times);
}

void cursor::left(int times) {
	printf("\033[%dC", times);
}

void cursor::right(int times) {
	printf("\033[%dD", times);
}

