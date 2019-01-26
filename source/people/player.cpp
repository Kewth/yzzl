#include "../../include/people/player.h"
#include "../../include/cursor.h"
#include "../../include/color.h"
#include "../../include/all_map.h"
#include "../../include/all_floor.h"

namespace people {
	Player::Player():
		People() {
		face = '@';
		color = new color::Blue();
	}
	Player::~Player() {
	}
	char Player::_get_face() {
		switch(_fg) {
			case 'w': return '^';
			case 's': return 'v';
			case 'a': return '<';
			case 'd': return '>';
			default: return face;
		}
	}
	int Player::login(std::string name, std::string pass) {
		// 在接口调好之前，先用着吧， ~~不碍事~~
		int res =
			system(("python3 ../python/user_login.py " + name  + " " + pass + " l").c_str());
		if(res == 0) {
			FILE *read =fopen("py_output", "r");
			fscanf(read, "exp: %lld\n", &m_exp);
		}
		return res;
	}
	int Player::regis(std::string name, std::string pass) {
		// 在接口调好之前，先用着吧， ~~不碍事~~
		int res =
			system(("python3 ../python/user_login.py " + name  + " " + pass + " r").c_str());
		if(res == 0) {
			FILE *read =fopen("py_output", "r");
			fscanf(read, "exp: %lld\n", &m_exp);
		}
		return res;
	}
	void Player::_print_map() {
		const int ha_high = 6, ha_width = 6; // 视野的半径（闭区间）
		cursor::clear_screen();
		for(int i=-ha_high; i<=ha_high; i++) {
			for(int j=-ha_width; j<=ha_width; j++) {
				if(not i and not j) { // Player 本身
					color->change_fore();
					putchar(_get_face());
				}
				else {
					People *p = _now_map->get_people(get_pos(), i, j);
					if(p) { // 该位置有人
						p->color->change_fore();
						putchar(p->face);
					} else {
						floor::Floor *f = _now_map->get_floor(get_pos(), i, j);
						if(f) {
							f->color->change_fore();
							putchar(f->face);
						} else {
							color->reset_fore();
							putchar(' ');
						}
					}
				}
			}
			std::cout << std::endl;
		}
	}
	void Player::_todo() {
		_print_map();
	}
};

