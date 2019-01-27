#ifndef input_H
#define input_H
namespace input {
	int getch(); // 读取键盘输入，不回显
	bool choose_in_cases
		(const char *accept_option, const char *denied_option);
	int ifgetch(double); // 在规定时间内 getch, 超时返回 -1
	bool chooseyn();
	bool kbhit(); // 返回是否有键盘输入
	void clear();
};
#endif
