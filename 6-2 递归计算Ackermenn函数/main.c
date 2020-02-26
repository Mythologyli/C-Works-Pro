#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现Ackermenn函数的计算

函数接口定义：
int Ack( int m, int n );

其中m和n是用户传入的非负整数。函数Ack返回Ackermenn函数的相应值。题目保证输入输出都在长整型范围内。
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