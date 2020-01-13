/*
C语言编程实现控制台上光标的随意移动
上下左右方向键移动光标
回车键光标换行
普通键盘区输入字符
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>

/*
定义一个句柄对象，虽然还没有看懂句柄到底是什么情况，但是我觉得这个句柄就代表控制台的一些属性，
有了句柄对象，我们就可以对这些属性进行操作
*/
HANDLE hout;

char get_input(void);	//获取用户输入

int main()
{
	char ch;

	hout = GetStdHandle(STD_OUTPUT_HANDLE);		//获取标准输出设备的句柄

	while (1)
	{
		ch = get_input();
		printf("%c", ch);//输出键盘字符
	}
}

//函数返回每个按键的键值
char get_input(void)
{
	int ch;			//输入字符串

	COORD coord;	//设置屏幕上的坐标
	CONSOLE_SCREEN_BUFFER_INFO csbi;	//控制台屏幕缓冲区信息

	coord.X = 10;	//设置光标坐标
	coord.Y = 10;

	ch = _getch();	//不带回显，不需要按回车，和getch一样，微软把函数统一为了下划线开头的

	//0X0D表示回车的键码，0XE0表示上下左右键的键码
	while (ch == 0XE0 || ch == 0X0D)
	{
		GetConsoleScreenBufferInfo(hout, &csbi);	//获取屏幕缓冲的光标位置,然后把当前光标位置赋给COORD
		coord.X = csbi.dwCursorPosition.X;			//得到坐标x的值
		coord.Y = csbi.dwCursorPosition.Y;			//y值

		if (ch == 0X0D)//回车
		{
			coord.X = 0;
			coord.Y++;
			SetConsoleCursorPosition(hout, coord);	//在输出设备上定位光标
			break;
		}

		ch = _getch();	//回车键换行之后可以继续输入，如果上面输入的就是方向键的话，这句就会被跳过

		if (ch == 0x48)//上
		{
			if (coord.Y != 0)
				coord.Y--;
		}
		else if (ch == 0x50)//下
		{
			coord.Y++;
		}
		else if (ch == 0x4b)//左
		{
			if (coord.X != 0)
				coord.X--;
		}
		else if (ch == 0x4d)//右
		{
			if (coord.X != 79)//向右写79个字换行
				coord.X++;
			else
			{
				coord.X = 0;
				coord.Y++;
			}
		}

		SetConsoleCursorPosition(hout, coord);//定位光标
		ch = _getch();	//继续输入,防止跳出while，输出方向键键值对应的字符
	}
	return ch;	//普通按键就返回键值，输出对应的字符
}