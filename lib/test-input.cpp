#include <stdio.h>
#include "input.h"
using namespace input;

int main(void)
{
	char accept[256], denied[256];
	int i;
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
	accept[5] = '\0';
	putchar('\n');
	puts("Enter 5 denied character:");
	for (i = 0; i < 5; ++i)
		putchar(denied[i] = getch());
	denied[5] = '\0';
	putchar('\n');
	puts("type some characters, q to quit:");
	puts("Test 10 times:");
	for (i = 0; i < 10; ++i)
		puts(choose_in_cases(accept, denied) ? "YES" : "NO");

	return 0;
}
