#include "../../include/map/maincity.h"
#include "../../include/floor/base_floor.h"

namespace map {
	Maincity::Maincity():
		Map(10, 10) {
		for(int i=0;i<high;i++)
			for(int j=0;j<width;j++)
				_floor(i, j) = new floor::Grass();
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
