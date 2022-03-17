#ifndef map_H
#define map_H
#include "../pos.h"
namespace people {
	class People;
};
namespace n_floor {
	class Floor;
};
namespace map {
	class Map {
	protected:
		pos::Coord_map<n_floor::Floor*> _floor;
		pos::Coord_map<people::People*> _people;
	public:
		int high, width;
		int people_move(people::People*, pos::Pos, pos::Pos);
		virtual pos::Pos recieve(people::People *) = 0;
		n_floor::Floor *get_floor(pos::Pos, int, int);
		people::People *get_people(pos::Pos, int, int);
		Map(int, int);
		virtual ~Map();
	};
};
#endif
