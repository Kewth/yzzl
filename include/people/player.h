#ifndef player_H
#define player_H
#include <iostream>
#include "people.h"
namespace people {
	class Player: public People {
	protected:
		void _todo();
	public:
		int login(std::string, std::string);
		int regis(std::string, std::string);
		Player();
	};
};
#endif
