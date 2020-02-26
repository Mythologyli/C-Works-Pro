#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个函数，对一个整数进行按位顺序输出。

函数接口定义：
void printdigits(int n);

函数printdigits应将n的每一位数字从高位到低位顺序打印出来，每位数字占一行。

输入样例：
12345

输出样例：
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