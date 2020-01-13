#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//printf 和 scanf 的使用
void printfAndScanf();
//输入小数点后多少位精度
void varwid();
//scanf * 修饰的用法
void skiptwo();
//printf %2之类的用法
void printWChar();

int main()
{

	//printfAndScanf();
	//varwid();
	//skiptwo();
	printWChar();
	return 0;
}

void printfAndScanf()
{
	//用 printf 输出 
	int a = 10;
	double b = 18.883438;
	float c = 18.8;
	char d = 'a';
	char arr[20] = " ";
	printf("---------------printf-------------\n");
	printf("a = %d\n", a);   //打印 int 类型的变量的值
	printf("b = %lf\n", b);   //打印 double 类型的变量的值
	printf("c = %f\n", c);   //打印 float 类型的变量的值
	printf("d = %c\n", d);   //打印 char 类型的变量的值
	printf("arr = %s\n", arr);   //打印 字符数组 类型的变量的值
	printf("---------------scanf-------------\n");
	//用 scanf 输入 各种类型
	printf("请输入a 的值:\n");
	scanf("%d", &a);
	printf("输入的 a 的值为：%d\n", a);
	printf("请输入b 的值:\n");
	scanf("%lf", &b);
	printf("输入的 b 的值为：%lf\n", b);
	printf("请输入c 的值:\n");
	scanf("%f", &c);
	printf("输入的 c 的值为：%f\n", c);
	getchar();
	printf("请输入d 的值:\n");
	scanf("%c", &d);
	printf("输入的 d 的值为：%c\n", d);
	getchar();
	printf("请输入arr 的值:\n");
	//如果输入的字符串里没有空格的话则使用scanf() 
	//scanf("%s", arr);
	gets_s(arr);
	//如果输入的字符串之间有空格 则改使用 gets()  gets(arr);
	printf("输入的 arr 的值为：%s\n", arr);
}

void varwid()
{
	unsigned width, precision;
	int number = 256;
	double weight = 242.5;
	printf("请输入一个字段宽度：\n");
	scanf("%d", &width);
	printf("这个数是 :%*d:\n",width,number);
	printf("现在输入一个宽度和一个精度：\n");
	scanf("%d %d", &width, &precision);
	printf("Weight = %*.*f\n", width, precision, weight);
	printf("Done! \n");
}

void skiptwo()
{
	int n;
	printf("请输入三个int类型的数:\n");
	scanf("%*d %*d %d", &n);
	printf("最后一次输入的数是：%d\n", n);
}

void printWChar()
{
	int a = 1, b = 23, c = 101;
	printf("没有规定字符宽度的输出:\n");
	printf("%d\n%d\n%d\n", a, b, c);
	printf("没有规定字符宽度为3的输出:\n");
	printf("%3d\n%3d\n%3d\n", a, b, c);
	double d = 19.123456789;
	printf("没有固定输出小数后几位:\n");
	printf("%lf\n", d);
	printf("固定输出小数后几位:\n");
	//%6.3lf 此处的6为规定打印所占位数
	printf("%6.3lf\n", d);
}

