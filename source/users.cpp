#include "../include/all_people.h"
#include "../include/users.h"
#include "../include/begin_flash.h"
#include "../include/input.h"
#include "../include/cursor.h"

static std::string get_name(std::string name, bool hide) {
	const int MAX_USER_NAME_LENGTH = 15;
	cursor::clear_screen();
	cursor::set_to(0, 0);
	char res[MAX_USER_NAME_LENGTH + 1];
	begin_flash::flash("请输入" + name + "：", false);
	int ch, size = 0;
	const char *info = " qwq ";
	while(size < MAX_USER_NAME_LENGTH) {
		/* output :----------|| 0/xx */
		for(int i=0; i<MAX_USER_NAME_LENGTH; ++i)
			putchar('-');
		printf("|| %d/%d \n", size, MAX_USER_NAME_LENGTH);

		printf("1. %s由大写或小写字母或数字组成\n", name.c_str());
		printf("2. %s长度不超过 %d\n", name.c_str(), MAX_USER_NAME_LENGTH);
		printf("3. 按 Enter 确认\n");
		printf("4. 按 Ctrl-H 删除\n");
		printf("%s\n", info);
		cursor::up(6);
		for(int i=0; i<size; i++)
			putchar(hide ? '*' : res[i]);
		cursor::to_head();
		ch = input::getch();
		if(ch == '\n' or ch == '\r') break;
		else if(ch == 127) { // Backspace
			if(not size)
				info = (name + "已空     ").c_str();
			else {
				size --;
				info = "             "; // 用于覆盖旧信息
			}
		} else if((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')
				or (ch >= '0' and ch <= '9')) {
			res[size ++] = ch;
			info = "             "; // 用于覆盖旧信息
		} else
			info = "非法字符     ";
	}
	return (std::string)res;
}

namespace users {
	int login(people::Player *p) {
		printf("登录（y)或注册（n)？");
		bool regis = ! input::chooseyn();
		std::string name = get_name("用户名", false);
		if(name.empty()) {
			puts("用户名为空！");
			return 1;
		}
		std::string pass = get_name("密码", true);
		if(pass.empty()) {
			puts("密码为空！");
			return 1;
		}
		if (regis) {
			if(pass != get_name("密码", true)) {
				puts("密码不匹配！");
				return 2;
			}
			int playeres = p->regis(name, pass);
			if(playeres) {
				puts("注册失败，可能用户名冲突");
				return 3;
			}
		} else {
			int playeres = p->login(name, pass);
			if(playeres) {
				puts("登录失败，可能用户名或密码错误");
				return 3;
			}
		}
		cursor::clear_screen(); // 清除登录/注册时的输出
		begin_flash::flash("成功获得用户", false);
		cursor::clear_screen();
		return 0;
	}
};
