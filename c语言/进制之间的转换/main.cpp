#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//将int 类型数字转换成char类型数组
void takeNumOfTen(int num, int times, char* arr)
{
	if (num % 10 != 0)
	{
		num < 0 ? num = -num : num = num;
		int num1 = num % 10;
		char num1Str = num1 + '0';
		arr[times] = num1Str;
		num /= 10;
		times++;
		takeNumOfTen(num, times, arr);
	}
}

//数字转成字符
char intToChar(int num)
{
	char ch = ' ';
	switch (num)
	{
	case 0:
		ch = '0';
		break;
	case 1:
		ch = '1';
		break;
	case 2:
		ch = '2';
		break;
	case 3:
		ch = '3';
		break;
	case 4:
		ch = '4';
		break;
	case 5:
		ch = '5';
		break;
	case 6:
		ch = '6';
		break;
	case 7:
		ch = '7';
		break;
	case 8:
		ch = '8';
		break;
	case 9:
		ch = '9';
		break;
	default:
		break;
	}
	return ch;
}

//递归方法取出余数     存储数组      转换的数字  次数        进制数
void takeTheRemainder(char* arr, int num, int times, int baseNum)
{
	short int a = 2;
	if (num / baseNum != 0)
	{
		int quotientNum = num / baseNum;
		int remainderNum = num % baseNum;
		printf("商数 = %d\n", quotientNum);
		printf("余数 = %d\n", remainderNum);
		char ch = intToChar(remainderNum);
		arr[times] = ch;
		times++;
		takeTheRemainder(arr, quotientNum, times, baseNum);
	}
	else
	{
		int remainderNum = num % baseNum;
		char ch = intToChar(remainderNum);
		arr[times] = ch;
	}
}
//从十进制转换成其他进制
void tenToOther(int num,int baseNum, char* arr)
{
	int times = 0;
	takeTheRemainder(arr, num, times, baseNum);
}
//从其他进制转换成十进制
char* otherToTen()
{
	char* arr = NULL;
	return arr;
}
int main()
{
	//定义一个num并初始化为12
	//int num = 12;
	//printf("十进制：%d\n", num);   //打印 num 的 十进制格式   
	//char numStr[10];
	//_itoa_s(num, numStr, 2);
	//printf("二进制：%s\n", numStr);//打印 num 的 二进制格式
	//printf("八进制：%o\n", num);   //打印 num 的 八进制格式
	//printf("十六进制：%x\n", num); //打印 num 的 十六进制格式
	/*char arr[100] = "";
	tenToOther(99, 13,arr);
	printf("arr = %s\n", arr);*/
	/*int num = 123;
	char numStr = 123 + '0';
	printf("numStr = %s\n", numStr);*/
	
	char arr[100] = " ";
	int times = 0;
	takeNumOfTen(9555555678, times, arr);
	printf("%s\n", arr);
	for (int i = strlen(arr)-1; i >= 0; i--)
	{
		printf("%c", arr[i]);
	}

	return 0;
}