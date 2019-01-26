#ifndef people_H
#define people_H
#include <queue>
#include "../pos.h"
namespace floor {
	class Floor;
};
namespace map {
	class Map;
};
namespace color {
	class Color;
};
namespace people {
	class People {
	protected:
		std::queue<map::Map *> _map;
		std::queue<pos::Pos> _pos;
		map::Map *_now_map;
		virtual void _todo() = 0;
		int _lv;
	public:
		color::Color *color;
		char face;
		long long m_exp;
		int goin(floor::Floor *); // 事件：进入地面
		void move(pos::Pos); // 在 Map 中移动到某位置
		void todo(); // 观察，作出决策
		void join_map(map::Map *);
		void leave_map();
		pos::Pos get_pos();
		People();
		virtual ~People();
	};
};
#endif
