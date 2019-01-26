#ifndef input_H
#define input_H
namespace input {
	int getch(); // 读取键盘输入，不回显
	bool choose_in_cases(int *accept, int accept_num,
		       	int *denied, int denied_num);
	bool chooseyn();
};
#endif
