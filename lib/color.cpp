#include <cstdio>
#include <cstdlib>
#include "../include/color.h"

namespace color {
	Color::~Color() {
	}
	void Color::change_fore() {
		_change_fore();
	}
	void Color::change_back() {
		_change_back();
	}
	void Color::reset_fore() {
		printf("\033[39m");
	}
	void Color::reset_back() {
		printf("\033[49m");
	}

	// 黑色字体
	Black::Black(int start): Color() {
		if(start & 1)
			change_fore();
		if(start & 2)
			change_back();
	}
	void Black::_change_fore() {
		printf("\033[30m");
	}
	void Black::_change_back() {
		printf("\033[40m");
	}

	// 白色字体
	White::White(int start): Color() {
		if(start & 1)
			change_fore();
		if(start & 2)
			change_back();
	}
	void White::_change_fore() {
		printf("\033[37m");
	}
	void White::_change_back() {
		printf("\033[47m");
	}

	// 绿色字体
	Green::Green(int start): Color() {
		if(start & 1)
			change_fore();
		if(start & 2)
			change_back();
	}
	void Green::_change_fore() {
		printf("\033[32m");
	}
	void Green::_change_back() {
		printf("\033[42m");
	}

	// 红色字体
	Red::Red(int start): Color() {
		if(start & 1)
			change_fore();
		if(start & 2)
			change_back();
	}
	void Red::_change_fore() {
		printf("\033[31m");
	}
	void Red::_change_back() {
		printf("\033[41m");
	}

	// 蓝色字体
	Blue::Blue(int start): Color() {
		if(start & 1)
			change_fore();
		if(start & 2)
			change_back();
	}
	void Blue::_change_fore() {
		printf("\033[34m");
	}
	void Blue::_change_back() {
		printf("\033[44m");
	}

	// 黄色字体
	Yellow::Yellow(int start): Color() {
		if(start & 1)
			change_fore();
		if(start & 2)
			change_back();
	}
	void Yellow::_change_fore() {
		printf("\033[33m");
	}
	void Yellow::_change_back() {
		printf("\033[43m");
	}

	// 紫色字体
	Purple::Purple(int start): Color() {
		if(start & 1)
			change_fore();
		if(start & 2)
			change_back();
	}
	void Purple::_change_fore() {
		printf("\033[33m");
	}
	void Purple::_change_back() {
		printf("\033[43m");
	}

	// 随机字体
	Random::Random(int start): Color() {
		if(start & 1)
			change_fore();
		if(start & 2)
			change_back();
	}
	void Random::_change_fore() {
		srand(rand());
		printf("\033[3%dm", rand() % 8);
	}
	void Random::_change_back() {
		srand(rand());
		printf("\033[4%dm", rand() % 8);
	}
};
