#include "../../include/people/player.h"

namespace people {
	Player::Player():
		People() {
	}
	Player::~Player() {
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
	void Player::_todo() {
	}
};

