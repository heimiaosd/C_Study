#include <stdio.h>

int main()
{
	int a = 2;
	printf("a+=2 a=%d\n", a+=2);
	int b = 2;
	b = b + 2;
	printf("b=b+2 b=%d\n\n", b);
	int c = 2;
	printf("c-=2 c=%d\n", c -= 2);
	int d = 2;
	d = d - 2;
	printf("d=d-2 d=%d\n\n", d);
	int e = 2;
	printf("e*=2 e=%d\n", e *= 2);
	int f = 2;
	f = f * 2;
	printf("f=f*2 f=%d\n\n", f);
	int g = 2;
	printf("g/=2 g=%d\n", g /= 2);
	int h = 2;
	h = h + 2;
	printf("h=h/2 h=%d\n\n", h);
	int i = 2;
	printf("i%%=2 i=%d\n", i %= 2);
	int j = 2;
	j = j % 2;
	printf("j=j%%2 j=%d\n", b);
	return 0;
}