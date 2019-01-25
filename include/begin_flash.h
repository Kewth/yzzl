#ifndef begin_flash_H
#define begin_flash_H
#include <iostream>
#include "pos.h"
namespace begin_flash {
	class Marix {
	protected:
		pos::Coord_map<char> _map;
	public:
		void ob_print(); // 斜向逐渐打印矩阵并使其消失
		void mid_disapeear(); // 使字符矩阵中间向四周消失
		Marix(pos::Coord_map<char>);
	};
	void welcome();
	void flash(std::string);
};
#endif
