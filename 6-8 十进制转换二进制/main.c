#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ����������������nת��Ϊ�����ƺ������

�����ӿڶ��壺
void dectobin(int n);

����dectobinӦ��һ���д�ӡ�������Ƶ�n�������õݹ�ʵ�֡�

����������
10

���������
1010
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

void dectobin(int n);

int main(void)
{
    int n;

    scanf("%d", &n);
    dectobin(n);

	return 0;
}

void dectobin(int n)
{
    if (n <= 1)
        printf("%d", n);
    else
    {
        dectobin(n / 2);
        printf("%d", n % 2);
    }
}