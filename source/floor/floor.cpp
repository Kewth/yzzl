#include "../../include/floor/floor.h"
#include "../../include/color.h"

namespace floor {
	void Floor::meet(people::People *p) {
		_meet(p);
	}
	Floor::Floor(color::Color *color, char face):
		color(color), face(face) {
	}
	Floor::~Floor() {
		delete color;
	}
};
