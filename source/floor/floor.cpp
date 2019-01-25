#include "../../include/floor/floor.h"
#include "../../include/color.h"

namespace floor {
	void Floor::meet(people::People *p) {
		_meet(p);
	}
	Floor::Floor(color::Color *_cr, char face):
		_cr(_cr), face(face) {
	}
	Floor::~Floor() {
		delete _cr; // color 无析构函数
	}
};
