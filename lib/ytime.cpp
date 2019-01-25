#include <sys/time.h>
#include <unistd.h>
#include "../include/ytime.h"

void ytime::ysleep(double time) {
	// 休眠 [time] 秒
	usleep(time * 1e6);
}

int ytime::clock() {
	// 获取程序运行时间
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv, &tz);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
