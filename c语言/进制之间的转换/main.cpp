#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//��int ��������ת����char��������
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

//����ת���ַ�
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

//�ݹ鷽��ȡ������     �洢����      ת��������  ����        ������
void takeTheRemainder(char* arr, int num, int times, int baseNum)
{
	short int a = 2;
	if (num / baseNum != 0)
	{
		int quotientNum = num / baseNum;
		int remainderNum = num % baseNum;
		printf("���� = %d\n", quotientNum);
		printf("���� = %d\n", remainderNum);
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
//��ʮ����ת������������
void tenToOther(int num,int baseNum, char* arr)
{
	int times = 0;
	takeTheRemainder(arr, num, times, baseNum);
}
//����������ת����ʮ����
char* otherToTen()
{
	char* arr = NULL;
	return arr;
}
int main()
{
	//����һ��num����ʼ��Ϊ12
	//int num = 12;
	//printf("ʮ���ƣ�%d\n", num);   //��ӡ num �� ʮ���Ƹ�ʽ   
	//char numStr[10];
	//_itoa_s(num, numStr, 2);
	//printf("�����ƣ�%s\n", numStr);//��ӡ num �� �����Ƹ�ʽ
	//printf("�˽��ƣ�%o\n", num);   //��ӡ num �� �˽��Ƹ�ʽ
	//printf("ʮ�����ƣ�%x\n", num); //��ӡ num �� ʮ�����Ƹ�ʽ
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