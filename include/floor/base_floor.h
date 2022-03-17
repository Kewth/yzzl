#ifndef base_floor_H
#define base_floor_H
#include "floor.h"
namespace n_floor {
	class First_floor: public Floor {
		// 一个 map 指定的入口
	protected:
		void _meet(people::People *);
	public:
		First_floor();
	};
	class End_floor: public Floor {
		// 一个 map 指定的出口
	protected:
		void _meet(people::People *);
		map::Map *_fa_m;
	public:
		End_floor();
	};
	class Grass: public Floor {
	protected:
		void _meet(people::People *);
	public:
		Grass();
	};
};
#endif
