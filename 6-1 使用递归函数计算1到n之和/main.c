#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ���õݹ����1+2+3+��+n�ĺ͵ļ򵥺�����

�����ӿڶ��壺
int sum(int n);

�ú������ڴ����������n����1+2+3+��+n�ĺͣ���n�����������򷵻�0����Ŀ��֤��������ڳ����ͷ�Χ�ڡ����鳢��д�ɵݹ麯����

��������1��
10

�������1��
55

��������2��
0

�������2��
0
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

int sum(int n);

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d\n", sum(n));

	return 0;
}

int sum(int n)
{
	if (n == 1)
		return 1;
	else if (n < 1)
		return 0;
	else return n + sum(n - 1);
}
