#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//printf �� scanf ��ʹ��
void printfAndScanf();
//����С��������λ����
void varwid();
//scanf * ���ε��÷�
void skiptwo();
//printf %2֮����÷�
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
	//�� printf ��� 
	int a = 10;
	double b = 18.883438;
	float c = 18.8;
	char d = 'a';
	char arr[20] = " ";
	printf("---------------printf-------------\n");
	printf("a = %d\n", a);   //��ӡ int ���͵ı�����ֵ
	printf("b = %lf\n", b);   //��ӡ double ���͵ı�����ֵ
	printf("c = %f\n", c);   //��ӡ float ���͵ı�����ֵ
	printf("d = %c\n", d);   //��ӡ char ���͵ı�����ֵ
	printf("arr = %s\n", arr);   //��ӡ �ַ����� ���͵ı�����ֵ
	printf("---------------scanf-------------\n");
	//�� scanf ���� ��������
	printf("������a ��ֵ:\n");
	scanf("%d", &a);
	printf("����� a ��ֵΪ��%d\n", a);
	printf("������b ��ֵ:\n");
	scanf("%lf", &b);
	printf("����� b ��ֵΪ��%lf\n", b);
	printf("������c ��ֵ:\n");
	scanf("%f", &c);
	printf("����� c ��ֵΪ��%f\n", c);
	getchar();
	printf("������d ��ֵ:\n");
	scanf("%c", &d);
	printf("����� d ��ֵΪ��%c\n", d);
	getchar();
	printf("������arr ��ֵ:\n");
	//���������ַ�����û�пո�Ļ���ʹ��scanf() 
	//scanf("%s", arr);
	gets_s(arr);
	//���������ַ���֮���пո� ���ʹ�� gets()  gets(arr);
	printf("����� arr ��ֵΪ��%s\n", arr);
}

void varwid()
{
	unsigned width, precision;
	int number = 256;
	double weight = 242.5;
	printf("������һ���ֶο�ȣ�\n");
	scanf("%d", &width);
	printf("������� :%*d:\n",width,number);
	printf("��������һ����Ⱥ�һ�����ȣ�\n");
	scanf("%d %d", &width, &precision);
	printf("Weight = %*.*f\n", width, precision, weight);
	printf("Done! \n");
}

void skiptwo()
{
	int n;
	printf("����������int���͵���:\n");
	scanf("%*d %*d %d", &n);
	printf("���һ����������ǣ�%d\n", n);
}

void printWChar()
{
	int a = 1, b = 23, c = 101;
	printf("û�й涨�ַ���ȵ����:\n");
	printf("%d\n%d\n%d\n", a, b, c);
	printf("û�й涨�ַ����Ϊ3�����:\n");
	printf("%3d\n%3d\n%3d\n", a, b, c);
	double d = 19.123456789;
	printf("û�й̶����С����λ:\n");
	printf("%lf\n", d);
	printf("�̶����С����λ:\n");
	//%6.3lf �˴���6Ϊ�涨��ӡ��ռλ��
	printf("%6.3lf\n", d);
}

