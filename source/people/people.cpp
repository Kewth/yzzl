#include "../../include/people/people.h"
#include "../../include/floor/floor.h"
#include "../../include/map/map.h"
#include "../../include/color.h"

namespace people {
	People::People():
		_lv(0), face('?'),  m_exp(0) {
	}
	People::~People() {
		delete color;
	}
	int People::goin(floor::Floor *f) {
		f->meet(this);
		// 之后在这提供派生类的接口
		return 0;
	}
	int People::move(pos::Pos ne) {
		// 在 _now_map 中移动
		int moveres = _now_map->people_move(this, _pos.front(), ne);
		if(moveres == 0) {
			_pos.pop();
			_pos.push(ne);
		}
		return moveres;
	}
	void People::todo() {
		_todo();
	}
	void People::join_map(map::Map *m) {
		_map.push(m);
		_now_map = m;
		pos::Pos ne = m->recieve(this);
		_pos.push(ne);
	}
	void People::leave_map() {
		_map.pop();
		_pos.pop();
		_now_map = _map.front();
	}
	pos::Pos People::get_pos() {
		return _pos.front();
	}
};
