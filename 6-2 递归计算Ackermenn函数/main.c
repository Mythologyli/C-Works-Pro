#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��Ackermenn�����ļ���

�����ӿڶ��壺
int Ack( int m, int n );

����m��n���û�����ķǸ�����������Ack����Ackermenn��������Ӧֵ����Ŀ��֤����������ڳ����ͷ�Χ�ڡ�
*/

int Ack(int m, int n);

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

int main(void)
{
	int m, n;

	scanf("%d %d", &m, &n);
	printf("%d\n", Ack(m, n));

	return 0;
}

int Ack(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (n == 0 && m > 0)
		return Ack(m - 1, 1);
	else return Ack(m - 1, Ack(m, n - 1));
}