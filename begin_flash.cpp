#include <iostream>
#include <cstring>
#include "head_file/ytime.h"
#include "head_file/color.h"
#include "head_file/cursor.h"
#include "head_file/begin_flash.h"

begin_flash::Marix::Marix(char s[12][30]): high(12), width(30) {
	for(int i=0;i<high;i++)
		for(int j=0;j<width;j++)
			_s[i][j] = s[i][j];
}

void begin_flash::Marix::ob_print() {
	color::Green gr;
	color::White wh;
	for(int t=0;t<width+high;t++) {
		for(int i=0;i<high;i++) {
			for(int j=0;j<width;j++)
				if(i + j == t) {
					wh.change_fore();
					std::cout << _s[i][j];
					gr.change_fore();
				} else if(i + j < t)
					std::cout << _s[i][j];
			std::cout << std::endl;
		}
		ytime::ysleep(0.1);
		cursor::up(high);
	}
	cursor::down(high);
}

void begin_flash::Marix::mid_disapeear() {
	cursor::up(high);
	color::Green gr(1);
	color::White wl;
	int rx = high >> 1, ry = width >> 1; // 矩阵中心坐标
	for(int t=0;t*2<width+high;t++) {
		for(int i=0;i<high;i++) {
			for(int j=0;j<width;j++)
				if(std::abs(i - rx) + std::abs(j - ry) < t)
					std::cout << ' ';
				else if(std::abs(i - rx) + std::abs(j - ry) == t) {
					wl.change_fore();
					std::cout << _s[i][j];
					gr.change_fore();
				} else
					std::cout << _s[i][j];
			std::cout << std::endl;
		}
		ytime::ysleep(0.1);
		cursor::up(high);
	}
}

void begin_flash::flash(std::string info) {
	// 以黑白加速闪动特效输出 [info]
	color::Color *cr[2] = {new color::Black(0), new color::White(0)};
	for(int i=0;i<20;i++) {
		cr[i & 1]->change_fore();
		std::cout << info << std::endl;
		cursor::up();
		ytime::ysleep(0.2 - 0.01 * i);
	}
}

void begin_flash::welcome() {
	// 欢迎界面
	begin_flash::flash("Welcome to yzzl");
	char s[12][30] = {
		"                      ''#    ",
		" m   m  mmmmm  mmmmm    #   _",
		" 'm m'     m'     m'    #__/ ",
		"  #m#    m'     m'      #    ",
		"  '#    #mmmm  #mmmm   /'mm  ",
		"  m'                __/      ",
		" ''           _____/     ^/  ",
		"             /        ==<@>==",
		"    ----- Created by    /v   ",
		"         __/ Kewth.K.D.      ",
		"                             ",
		"                             ",
	};
	begin_flash::Marix ma(s);
	ma.ob_print();
	ma.mid_disapeear();
}
