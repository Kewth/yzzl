#include <stdio.h>
#include "input.h"
using namespace input;

int main(void)
{
	int accept[256], i, denied[256];
	puts("testing:getch():");
	puts("type some characters below, q to quit");
	while (i != 'q')
		printf("you press:%c\n", (i = getch()));

	puts("testing:chooseyn() (four times)");
	for (i = 0; i < 4; ++i) {
		printf("Choose(y/n):");
		puts(chooseyn() ? "YES" : "NO");
	}

	puts("testing:choose_in_case()");
	puts("Enter 5 accept character:");
	for (i = 0; i < 5; ++i)
		putchar(accept[i] = getch());
	putchar('\n');
	puts("Enter 5 denied character:");
	for (i = 0; i < 5; ++i)
		putchar(denied[i] = getch());
	putchar('\n');
	puts("type some characters, q to quit:");
	puts("Test 10 times:");
	for (i = 0; i < 10; ++i)
		puts(choose_in_cases(accept, 5, denied, 5) ? "YES" : "NO");

	return 0;
}
