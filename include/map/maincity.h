#ifndef maincity_H
#define maincity_H
#include "map.h"
namespace map {
	class Maincity: public Map {
		// 主城
	protected:
	public:
		pos::Pos recieve(people::People *);
		Maincity();
		~Maincity();
	};
};
#endif
