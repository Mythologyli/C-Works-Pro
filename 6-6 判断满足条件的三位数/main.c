#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ��������ͳ�Ƹ��������ڵ���λ��������λ������ͬ����ȫƽ��������144��676���ĸ�����

�����ӿڶ��壺
int search( int n );

���д���Ĳ���int n��һ����λ���������������λ���ַ�0��������search����[101, n]�����������������������ĸ�����

����������
500

���������
count=6
*/

#include <stdio.h>
#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

int search(int n);

int main(void)
{
	int number;

	scanf("%d", &number);
	printf("count=%d\n", search(number));

	return 0;
}

int search(int n)
{
	if (n <= 101)
		return 0;
	else
	{
		int count = 0;
		
		for (int i = 101; i <= n; i++)
		{
			if (sqrt(i) == (int)sqrt(i)) //�ж��Ƿ�Ϊ��ȫƽ����
			{
				char num[4] = { 0 };
				sprintf(num, "%d", i);
				if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) //�ж��Ƿ����������
					count++;
			}
		}

		return count;
	}
}