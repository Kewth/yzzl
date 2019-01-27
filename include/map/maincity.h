#ifndef maincity_H
#define maincity_H
#include "map.h"
#include "../floor/floor.h"
namespace map {
	class Maincity: public Map {
		// 主城
	private:
		class _thanks: public floor::Floor {
		protected:
			void _meet(people::People *);
		public:
			_thanks();
		};
	protected:
	public:
		pos::Pos recieve(people::People *);
		Maincity();
		~Maincity();
	};
};
#endif
