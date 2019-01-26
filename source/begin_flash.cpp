#include <iostream>
#include <cstring>
#include "../include/ytime.h"
#include "../include/color.h"
#include "../include/cursor.h"
#include "../include/begin_flash.h"

begin_flash::Marix::Marix(pos::Coord_map<char> _map):
	_map(_map) {
}

void begin_flash::Marix::ob_print() {
	color::Green gr;
	color::White wh;
	for(int t=0; t<_map.high+_map.width; t++) {
		for(int i=0; i<_map.high; i++) {
			for(int j=0; j<_map.width; j++)
				if(i + j == t) {
					wh.change_fore();
					std::cout << _map(i, j);
					gr.change_fore();
				} else if(i + j < t)
					std::cout << _map(i, j);
			std::cout << std::endl;
		}
		ytime::ysleep(0.1);
		cursor::up(_map.high);
	}
	cursor::down(_map.high);
}

void begin_flash::Marix::mid_disapeear() {
	cursor::up(_map.high);
	color::Green gr(1);
	color::White wl;
	int rx = _map.high >> 1, ry = _map.width >> 1; // 矩阵中心坐标
	for(int t=0; t*2<_map.high+_map.width; t ++) {
		for(int i=0; i<_map.high; i++) {
			for(int j=0; j<_map.width; j++)
				if(std::abs(i - rx) + std::abs(j - ry) < t)
					std::cout << ' ';
				else if(std::abs(i - rx) + std::abs(j - ry) == t) {
					wl.change_fore();
					std::cout << _map(i, j);
					gr.change_fore();
				} else
					std::cout << _map(i, j);
			std::cout << std::endl;
		}
		ytime::ysleep(0.1);
		cursor::up(_map.high);
	}
}

void begin_flash::flash(std::string info, bool speedup) {
	// 以黑白加速闪动特效输出 [info]
	color::Color *cr[2] = {new color::Black(0), new color::White(0)};
	for(int i=0; i < (speedup?20:10); i++) {
		cr[i & 1]->change_fore();
		std::cout << info << std::endl;
		cursor::up();
		if(speedup)
			ytime::ysleep(0.2 - 0.01 * i);
		else
			ytime::ysleep(0.2);
	}
	delete cr[0];
	delete cr[1];
}

void begin_flash::welcome() {
	// 欢迎界面
	cursor::clear_screen();
	cursor::set_to(0, 0);
	begin_flash::flash("Welcome to yzzl", true);
	const int high = 11, width = 30;
	char s[high][width] = {
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
	};
	pos::Coord_map<char> map(high, width);
	for(int i=0; i<high; i++)
		for(int j=0; j<width; j++)
			map(i, j) = s[i][j];
	begin_flash::Marix mar(map);
	mar.ob_print();
	mar.mid_disapeear();
}
