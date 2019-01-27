#include <iostream>
#include <cstring>
#include <functional>
#include "../include/ytime.h"
#include "../include/color.h"
#include "../include/cursor.h"
#include "../include/begin_flash.h"
#include "../include/ascii_flash.h"

namespace begin_flash {
	Marix::Marix(pos::Coord_map<char> _map):
		_map(_map) {
	}

	void Marix::ob_print() {
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
		gr.reset_fore();
	}

	void Marix::mid_disapeear() {
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
		gr.reset_fore();
	}

	void flash(std::string info, bool speedup) {
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
		cr[0]->reset_fore();
		delete cr[0];
		delete cr[1];
	}

	void welcome() {
		// 欢迎界面
		cursor::clear_screen();
		cursor::set_to(0, 0);
		begin_flash::flash("Welcome to yzzl", true);
		const int flash_sl = 6;
		std::function<pos::Coord_map<char>()> flash[flash_sl]
			= {Flash1, Flash2, Flash3, Flash4, Flash5, Flash6 };
		srand(time(0));
		begin_flash::Marix mar(flash[rand()%flash_sl]());
		mar.ob_print();
		mar.mid_disapeear();
	}

	void thanks() {
		// 鸣谢
		cursor::clear_screen();
		cursor::set_to(0, 0);
		begin_flash::flash("Yzzl 的诞生还要感谢许多人和软件、网站", false);
		const int high = 5, width = 80;
		const char s[high][width] = {
			"                                                       ",
			"“刘大侠”: 最古老的《勇者之路》提供了这个 idea          ",
			"Ld_liaomo: 帮助实现和完善了 yzzl 用到的库              ",
			"https://www.bootschool.net/ascii: 开场动画艺术字来源   ",
			"                                                       ",
		};
		pos::Coord_map<char> cmap(high, width);
		for(int i=0;i<high;i++)
			for(int j=0;j<width;j++)
				cmap(i, j) = s[i][j] ? s[i][j] : ' ';
		begin_flash::Marix mar(cmap);
		mar.ob_print();
		mar.mid_disapeear();
	}
};
