#include "../../include/floor/base_floor.h"
#include "../../include/people/people.h"
#include "../../include/color.h"

namespace floor {
	First_floor::First_floor():
		Floor(new color::Purple(), '+') {
	}
	void First_floor::_meet(people::People *) { } // 入口不会有任何响应
	End_floor::End_floor():
		Floor(new color::Purple(), '!') {
	}
	void End_floor::_meet(people::People *p) {
		p->leave_map();
	}
	Grass::Grass():
		Floor(new color::Green(), '*') {
	}
	void Grass::_meet(people::People *) { } // 草地不会有任何响应
};
