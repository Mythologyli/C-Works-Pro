#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ����������һ���������а�λ˳�������

�����ӿڶ��壺
void printdigits(int n);

����printdigitsӦ��n��ÿһλ���ִӸ�λ����λ˳���ӡ������ÿλ����ռһ�С�

����������
12345

���������
1
2
3
4
5
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

void printdigits(int n);

int main(void)
{
	int n;

	scanf("%d", &n);
	printdigits(n);


	return 0;
}

void printdigits(int n)
{
	if (n < 0)
		n = -n;

	if (n < 10)
		printf("%d\n", n);
	else
	{
		printdigits(n / 10);
		printf("%d\n", n % 10);
	}
}