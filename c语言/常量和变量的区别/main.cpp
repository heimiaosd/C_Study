//����������  
//1.�����ĺ��壺���ܱ��ı�ı�����֮Ϊ���� 
//2.д���淶�������ı�����һ��Ҫ��д  һ���д���ļ���ͷ��
//3.�������÷���#define ������ ֵ
//4.����������㣺���峣���������������ͣ����Գ������Դ洢�κ����͵�����
//5.����ֻ�ܱ���ֵһ��
#define NUM 10       //�˴� NUM    ������Ϊ  int 
#define WEIGHT 18.44 //�˴� WEIGHT ������Ϊ  double
#define CSTR   'a'   //�˴� CSTR   ������Ϊ  char
#define STR  "str"   //�˴� STR    ������Ϊ  char[](�ַ�����)

//ͷ�ļ�
#include <stdio.h>



//�������
int main()
{
	double weight = 18.889;
	printf("�ı�ǰ weight = %lf\n", weight);   //��ӡ weight �ı�ǰ��ֵ
	weight = 20.88;
	printf("�ı�� weight = %lf\n", weight);   //��ӡ weight �ı���ֵ
	//WEIGHT = 10  ����д���Ǵ���ģ� ��Ϊ������ֵ���ɸı�

	return 1;  //�����ķ���ֵ ����Ϊ main �����ķ���ֵ�� int �������Դ˴�Ҫ���� һ�� int ���͵�������
}