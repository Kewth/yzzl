#ifndef map_H
#define map_H
#include "../pos.h"
namespace people {
	class People;
};
namespace floor {
	class Floor;
};
namespace map {
	class Map {
	protected:
		pos::Coord_map<floor::Floor*> _floor;
		pos::Coord_map<people::People*> _people;
	public:
		int high, width;
		int people_move(people::People*, pos::Pos, pos::Pos);
		virtual pos::Pos recieve(people::People *) = 0;
		Map(int, int);
		virtual ~Map();
	};
};
#endif
