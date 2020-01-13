#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

//-------------------定义数据部分----------------//

//---------------函数声明部分-------------------//
//计数循环
void sweetiel();

//打印字符三角形
void printCh();

int main()
{
	printf("---------for循环---------\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n",i);
	}
	printf("---------while循环---------\n");
	int j = 0;
	while (j<10)
	{
		printf("%d\n", j);
		j++;
	} 
	printf("---------do while循环---------\n");
	int k = 0;
	do
	{
		printf("%d\n", k);
		k++;
	} while (k<10);
	sweetiel();
	printCh();
	return 0;
}

void sweetiel()
{
	const int num = 22;
	int count = 1; //初始化
	while (count<=num)
	{
		printf("计数器加一\n");
		count++;
	}
#if 0
	//for死循环的写法
	for (;;)
	{
	}
	//while死循环的写法
	while (true)
	{

	}
#endif // 0

}

void printCh()
{
	char ch;
	int row = 6;
	int col = 6;
	int index = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j=0;j<col-i;j++)
		{
			printf("%c", 'A'+index);
			index++;
		}
			
		printf("\n");
	}
}
