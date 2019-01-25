#include "../../include/people/people.h"
#include "../../include/floor/floor.h"
#include "../../include/map/map.h"

namespace people {
	People::People():
		_lv(0), m_exp(0) {
	}
	People::~People() {
	}
	int People::goin(floor::Floor *f) {
		f->meet(this);
		// 之后在这提供派生类的接口
		return 0;
	}
	void People::move(pos::Pos ne) {
		_now_map->people_move(this, _pos[_now_map], ne); // 在 _now_map 中移动
	}
	void People::todo() {
		_todo();
	}
};
