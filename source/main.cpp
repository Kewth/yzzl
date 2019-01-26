#include "../include/begin_flash.h"
#include "../include/all_people.h"
#include "../include/all_map.h"
#include "../include/users.h"
#include "../include/input.h"

int main(int, const char **) {
	begin_flash::welcome();
	people::Player *self = new people::Player();
	users::login(self);
	map::Map *city = new map::Maincity();
	self->join_map(city);
	while(true) {
		self->todo();
		int choose = input::getch();
		if(choose == 'q')
			break;
	}
	delete self;
	delete city;
}
