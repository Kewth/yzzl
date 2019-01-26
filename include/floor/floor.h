#ifndef floor_H
#define floor_H
namespace people {
	class People;
};
namespace map {
	class Map;
};
namespace color {
	class Color;
};
namespace floor {
	class Floor {
	protected:
		virtual void _meet(people::People *) = 0;
	public:
		color::Color *color;
		char face;
		void meet(people::People *); // 某角色进入
		Floor(color::Color*, char);
		virtual ~Floor();
	};
};
#endif
