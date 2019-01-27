#include "../include/ascii_flash.h"
#include "../include/pos.h"

namespace begin_flash {
	pos::Coord_map<char> Flash1() { // toilet
		const int high = 11, width = 30;
		char s[high][width] = {
			"                      ''#    ",
			" m   m  mmmmm  mmmmm    #   _",
			" 'm m'     m'     m'    #__/ ",
			"  #m#    m'     m'      #    ",
			"  '#    #mmmm  #mmmm   /'mm  ",
			"  m'                __/      ",
			" ''           _____/     ^/  ",
			"             /        ==<@>==",
			"----- Created by        /v   ",
			" __/ Kewth.K.D. and ld_liaomo",
			"                             ",
		};
		pos::Coord_map<char> map(high, width);
		for(int i=0; i<high; i++)
			for(int j=0; j<width; j++)
				map(i, j) = s[i][j];
		return map;
	}

	pos::Coord_map<char> Flash2() { // banner3-D
		const int high = 12, width = 41;
		char s[high][width] = {
			"'##:::'##:'########:'########:'##:::::::",
			". ##:'##::..... ##::..... ##:: ##:::::::",
			":. ####::::::: ##::::::: ##::: ##:::::::",
			"::. ##::::::: ##::::::: ##:::: ##:::::::",
			"::: ##:::::: ##::::::: ##::::: ##:::::::",
			"::: ##::::: ##::::::: ##:::::: ##:::::::",
			"::: ##:::: ########: ########: ########:",
			":::..:::::........::........::........::",
			"::::::::::::::::::::::::::::::::::::::::",
			"::::::: ----- Created by :::::::::::::::",
			"::::::::::::::::::::: Kewth.K.D ::::::::",
			"::::::::::::::::::::::::::::::::::::::::",
		};
		pos::Coord_map<char> map(high, width);
		for(int i=0; i<high; i++)
			for(int j=0; j<width; j++)
				map(i, j) = s[i][j];
		return map;
	}

	pos::Coord_map<char> Flash3() { // bell
		const int high = 9, width = 26;
		char s[high][width] = {
			"                      .  ",
			" ,    .  ____  ____   |  ",
			" |    `     /     /   |  ",
			" |    |   ,/    ,/    |  ",
			"  `---|. /__.' /__.' /\\__",
			"  \\___/  `     `         ",
			"                         ",
			"   ----- created by      ",
			"             Kewth.K.D   ",
		};
		pos::Coord_map<char> map(high, width);
		for(int i=0; i<high; i++)
			for(int j=0; j<width; j++)
				map(i, j) = s[i][j];
		return map;
	}

	pos::Coord_map<char> Flash4() { // emmm
		const int high = 10, width = 32;
		char s[high][width] = {
			"                            _//",
			"                            _//",
			"_//   _//_//// _//_//// _// _//",
			" _// _//      _//      _//  _//",
			"   _///     _//      _//    _//",
			"    _//    _//      _//     _//",
			"   _//   _////////_////////_///",
			" _//                           ",
			"        ----- Created by       ",
			"                 Kewth.K.D     ",
		};
		pos::Coord_map<char> map(high, width);
		for(int i=0; i<high; i++)
			for(int j=0; j<width; j++)
				map(i, j) = s[i][j];
		return map;
	}

	pos::Coord_map<char> Flash5() { // isometric1
		const int high = 13, width = 53;
		char s[high][width] = {
			"      ___           ___           ___           ___ ",
			"     |\\__\\         /\\  \\         /\\  \\         /\\__\\",
			"     |:|  |        \\:\\  \\        \\:\\  \\       /:/  /",
			"     |:|  |         \\:\\  \\        \\:\\  \\     /:/  / ",
			"     |:|__|__        \\:\\  \\        \\:\\  \\   /:/  /  ",
			"     /::::\\__\\ _______\\:\\__\\ _______\\:\\__\\ /:/__/   ",
			"    /:/~~/~    \\::::::::/__/ \\::::::::/__/ \\:\\  \\   ",
			"   /:/  /       \\:\\~~\\~~      \\:\\~~\\~~      \\:\\  \\  ",
			"   \\/__/         \\:\\  \\        \\:\\  \\        \\:\\  \\ ",
			"                  \\:\\__\\        \\:\\__\\        \\:\\__\\",
			"                   \\/__/         \\/__/         \\/__/",
			"                                                    ",
			"     ----- Created by Kewth.K.D                     ",
		};
		pos::Coord_map<char> map(high, width);
		for(int i=0; i<high; i++)
			for(int j=0; j<width; j++)
				map(i, j) = s[i][j];
		return map;
	}

	pos::Coord_map<char> Flash6() { // isometric3
		const int high = 12, width = 55;
		char s[high][width] = {
			"      ___        /  /\\         /  /\\                  ",
			"     /__/|      /  /::|       /  /::|                 ",
			"    |  |:|     /  /:/:|      /  /:/:|     ___     ___ ",
			"    |  |:|    /  /:/|:|__   /  /:/|:|__  /__/\\   /  /\\",
			"  __|__|:|   /__/:/ |:| /\\ /__/:/ |:| /\\ \\  \\:\\ /  /:/",
			" /__/::::\\   \\__\\/  |:|/:/ \\__\\/  |:|/:/  \\  \\:\\  /:/ ",
			"    ~\\~~\\:\\      |  |:/:/      |  |:/:/    \\  \\:\\/:/  ",
			"      \\  \\:\\     |  |::/       |  |::/      \\  \\::/   ",
			"       \\__\\/     |  |:/        |  |:/        \\__\\/    ",
			"                 |__|/         |__|/                  ",
			"                                                      ",
			"       ----- Created by Kewth.K.D                     ",
		};
		pos::Coord_map<char> map(high, width);
		for(int i=0; i<high; i++)
			for(int j=0; j<width; j++)
				map(i, j) = s[i][j];
		return map;
	}

};
