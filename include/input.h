#ifndef input_H
#define input_H
namespace input {
	int getch(); // 读取键盘输入，不回显
	bool choose_in_cases
		(const char *accept_option, const char *denied_option);
	bool chooseyn();
};
#endif
