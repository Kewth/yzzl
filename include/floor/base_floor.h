#ifndef base_floor_H
#define base_floor_H
#include "floor.h"
namespace floor {
	class First_floor: public Floor {
		// 一个 map 指定的入口
	protected:
		void _meet(people::People *);
	public:
		First_floor();
	};
	class Grass: public Floor {
	protected:
		void _meet(people::People *);
	public:
		Grass();
	};
};
#endif
