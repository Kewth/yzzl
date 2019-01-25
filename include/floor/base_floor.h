#ifndef base_floor_H
#define base_floor_H
#include "floor.h"
namespace floor {
	class Grass: public Floor {
	protected:
		void _meet(people::People *);
	public:
		Grass();
	};
};
#endif
