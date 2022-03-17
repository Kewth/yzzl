#include "../../include/people/people.h"
#include "../../include/floor/floor.h"
#include "../../include/map/map.h"
#include "../../include/color.h"

namespace people {
	People::People(color::Color *color, char face, int clever):
		_lv(0), color(color), face(face),  m_exp(0), clever(clever) {
	}
	People::~People() {
		delete color;
	}
	int People::goin(n_floor::Floor *f) {
		f->meet(this);
		// 之后在这提供派生类的接口
		return 0;
	}
	int People::move(pos::Pos ne) {
		// 在 _now_map 中移动
		int moveres = get_map()->people_move(this, _pos.front(), ne);
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
		pos::Pos ne = m->recieve(this);
		_pos.push(ne);
	}
	void People::leave_map() {
		_map.pop();
		_pos.pop();
	}
	pos::Pos People::get_pos() {
		if(_pos.empty())
			return pos::Pos(0, 0);
		return _pos.front();
	}
	map::Map *People::get_map() {
		if(_map.empty())
			return nullptr;
		return _map.front();
	}
};
