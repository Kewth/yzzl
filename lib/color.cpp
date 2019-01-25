#include <cstdio>
#include "../include/color.h"

void color::Color::change_fore() {
	_change_fore();
}

void color::Color::change_back() {
	_change_back();
}

// 黑色字体
color::Black::Black(int start): Color() {
	if(start & 1)
		change_fore();
	if(start & 2)
		change_back();
}

void color::Black::_change_fore() {
	printf("\033[30m");
}

void color::Black::_change_back() {
	printf("\033[40m");
}

// 白色字体
color::White::White(int start): Color() {
	if(start & 1)
		change_fore();
	if(start & 2)
		change_back();
}

void color::White::_change_fore() {
	printf("\033[37m");
}

void color::White::_change_back() {
	printf("\033[47m");
}

// 绿色字体
color::Green::Green(int start): Color() {
	if(start & 1)
		change_fore();
	if(start & 2)
		change_back();
}

void color::Green::_change_fore() {
	printf("\033[32m");
}

void color::Green::_change_back() {
	printf("\033[42m");
}

