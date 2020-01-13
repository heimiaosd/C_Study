#include <stdio.h>

int main()
{
	printf("---------a++------------\n");
	int a = 2;
	int c = 2 * a++;
	printf("c = %d\n", c);
	printf("---------++a------------\n");
	int b = 2;
	int d = 2 * ++b;
	printf("d = %d\n", d);
}