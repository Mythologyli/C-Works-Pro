#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个用递归计算1+2+3+…+n的和的简单函数。

函数接口定义：
int sum(int n);

该函数对于传入的正整数n返回1+2+3+…+n的和；若n不是正整数则返回0。题目保证输入输出在长整型范围内。建议尝试写成递归函数。

输入样例1：
10

输出样例1：
55

输入样例2：
0

输出样例2：
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
