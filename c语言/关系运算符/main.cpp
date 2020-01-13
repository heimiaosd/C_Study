#include <stdio.h>

int main()
{
	int a = 5, b = 6;
	if (a < b)
		printf("a小于b\n");
	else if (a <= b)
		printf("a小于等于b\n");
	else if (a == b)
		printf("a等于b\n");
	else if (a >= b)
		printf("a大于等于b\n");
	else if (a > b)
		printf("a大于b\n");
	else if (a != b)
		printf("a不等于b\n");
	return 0;
}