#ifndef people_H
#define people_H
#include <map>
#include "../pos.h"
namespace floor {
	class Floor;
};
namespace map {
	class Map;
};
namespace people {
	class People {
	protected:
		std::map<map::Map*, pos::Pos> _pos;
		map::Map *_now_map;
		virtual void _todo() = 0;
	public:
		int goin(floor::Floor *); // 事件：进入地面
		void move(pos::Pos); // 在 Map 中移动到某位置
		void todo(); // 观察，作出决策
	};
};
#endif
