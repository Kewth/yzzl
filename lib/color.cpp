#include <cstdio>
#include "../include/color.h"

namespace color {
	void Color::change_fore() {
		_change_fore();
	}
	void Color::change_back() {
		_change_back();
	}
	Color::~Color() {
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

};
