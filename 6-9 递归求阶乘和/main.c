#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ������Ǹ������׳˵ļ򵥺����������øú����� 1!+2!+3!+...+n! ��ֵ��

�����ӿڶ��壺
double fact(int n);
double factsum(int n);

����factӦ����n�Ľ׳ˣ������õݹ�ʵ�֡�����factsumӦ���� 1!+2!+...+n! ��ֵ����Ŀ��֤���������˫���ȷ�Χ�ڡ�

��������1��
10

�������1��
fact(10) = 3628800
sum = 4037913

��������2��
0

�������2��
fact(0) = 1
sum = 0
*/

double fact(int n);
double factsum(int n);

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));

	return 0;
}

double fact(int n)
{
    if (n <= 1)
        return 1;
    else return n * fact(n - 1);
}

double factsum(int n)
{
    int sum = 0;
    
    for (int i = 1; i <= n; i++)
        sum += fact(i);

    return sum;
}