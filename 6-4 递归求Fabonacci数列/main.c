#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现求Fabonacci数列项的函数。Fabonacci数列的定义如下：
f(n)=f(n−2)+f(n−1) (n≥2)，其中f(0)=0，f(1)=1。

函数接口定义：
int f( int n );

函数f应返回第n个Fabonacci数。题目保证输入输出在长整型范围内。建议用递归实现。

输入样例：
6

输出样例：
8
*/

int f(int n);

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d\n", f(n));

	return 0;
}

int f(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else return f(n - 2) + f(n - 1);
}