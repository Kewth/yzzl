#include "../../include/floor/base_floor.h"
#include "../../include/color.h"

namespace floor {
	First_floor::First_floor():
		Floor(new color::Purple(), '+') {
	}
	void First_floor::_meet(people::People *) { } // 入口不会有任何响应
	Grass::Grass():
		Floor(new color::Green(), '*') {
	}
	void Grass::_meet(people::People *) { } // 草地不会有任何响应
};
