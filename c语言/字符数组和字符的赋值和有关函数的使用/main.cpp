#include <stdio.h>
#include <string.h>

int main()
{
	//const修饰的变量不可二次修改
	const char ch = 'a';
	//ch = 'b';
	//字符串以 空字符 \0 结尾
	char arr[6] = "hello";
	printf("sizeof(arr) = %d\n", sizeof(arr));
	//strlen(数组名) 用来计算数组内元素的个数  返回值为 int
	//strlen(数组名) 不会计算字符串结尾处的无效字符\0  只计算有效字符
	int len = strlen(arr);
	printf("len = %d\n", len);
	return 0;
}