#include "../../include/floor/base_floor.h"
#include "../../include/color.h"

namespace floor {
	void Grass::_meet(people::People *) { } // 草地不会有任何响应
	Grass::Grass():
		Floor(new color::Green(), '*') {
	}
};
