#include "../../include/map/maincity.h"
#include "../../include/floor/base_floor.h"
#include "../../include/people/people.h"
#include "../../include/color.h"
#include "../../include/begin_flash.h"

namespace map {
	Maincity::_thanks::_thanks():
		Floor(new color::Green, 'T') {
	}
	void Maincity::_thanks::_meet(people::People *p) {
		if(p->clever >= 3)
			begin_flash::thanks();
	}
	Maincity::Maincity():
		Map(10, 20) {
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
					_floor(i, j) = new n_floor::Grass();
		// 创造出口
		delete _floor(9, 9);
		_floor(9, 9) = new n_floor::End_floor();
		// 鸣谢
		for(int j=10;j<19;j++)
			_floor(5, j) = new n_floor::Grass();
		_floor(5, 19) = new _thanks();
	}
	Maincity::~Maincity() {
	}
	pos::Pos Maincity::recieve(people::People *p) {
		for(int i=0;i<high;i++)
			for(int j=0;j<width;j++)
				if(not _people(i, j)) {
					_people(i, j) = p;
					return pos::Pos(i, j);
				}
		return pos::Pos(0, 0); // 应该不会有这种情况。。。
	}
};
