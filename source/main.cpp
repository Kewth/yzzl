#include "../include/begin_flash.h"
#include "../include/all_people.h"
#include "../include/users.h"

int main(int, const char **) {
	begin_flash::welcome();
	people::Player *self = new people::Player();
	users::login(self);
}
