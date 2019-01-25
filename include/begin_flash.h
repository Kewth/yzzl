#ifndef begin_flash_H
#define begin_flash_H
#include <iostream>
namespace begin_flash {
	class Marix {
	protected:
		char _s[12][30];
		int high, width;
	public:
		void ob_print(); // 斜向逐渐打印矩阵并使其消失
		void mid_disapeear(); // 使字符矩阵中间向四周消失
		Marix(char [12][30]);
	};
	void welcome();
	void flash(std::string);
};
#endif
