#include <stdio.h>

int main()
{
	int a = 5, b = 6;
	if (a < b)
		printf("aС��b\n");
	else if (a <= b)
		printf("aС�ڵ���b\n");
	else if (a == b)
		printf("a����b\n");
	else if (a >= b)
		printf("a���ڵ���b\n");
	else if (a > b)
		printf("a����b\n");
	else if (a != b)
		printf("a������b\n");
	return 0;
}