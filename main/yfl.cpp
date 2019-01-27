#include "../include/begin_flash.h"

int main(int, char **) {
	int times = 0;
	while(true) {
		(times += 1) %= 4;
		if(times)
			begin_flash::welcome();
		else
			begin_flash::thanks();
	}
}
