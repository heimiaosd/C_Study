#include <stdio.h>
#include <string.h>

int main()
{
	//const���εı������ɶ����޸�
	const char ch = 'a';
	//ch = 'b';
	//�ַ����� ���ַ� \0 ��β
	char arr[6] = "hello";
	printf("sizeof(arr) = %d\n", sizeof(arr));
	//strlen(������) ��������������Ԫ�صĸ���  ����ֵΪ int
	//strlen(������) ��������ַ�����β������Ч�ַ�\0  ֻ������Ч�ַ�
	int len = strlen(arr);
	printf("len = %d\n", len);
	return 0;
}