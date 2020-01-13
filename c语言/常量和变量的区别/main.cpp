//常量的声明  
//1.常量的含义：不能被改变的变量称之为常量 
//2.写法规范：常量的变量名一般要大写  一般会写在文件开头处
//3.常量的用法：#define 常量名 值
//4.常量的特殊点：定义常量不会检查数据类型，所以常量可以存储任何类型的数据
//5.常量只能被赋值一次
#define NUM 10       //此处 NUM    的类型为  int 
#define WEIGHT 18.44 //此处 WEIGHT 的类型为  double
#define CSTR   'a'   //此处 CSTR   的类型为  char
#define STR  "str"   //此处 STR    的类型为  char[](字符数组)

//头文件
#include <stdio.h>



//程序入口
int main()
{
	double weight = 18.889;
	printf("改变前 weight = %lf\n", weight);   //打印 weight 改变前的值
	weight = 20.88;
	printf("改变后 weight = %lf\n", weight);   //打印 weight 改变后的值
	//WEIGHT = 10  这种写法是错误的， 因为常量的值不可改变

	return 1;  //函数的返回值 （因为 main 函数的返回值是 int 类型所以此处要返回 一个 int 类型的整数）
}