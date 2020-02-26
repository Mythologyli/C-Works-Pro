#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个计算x^​n​​（n≥1）的函数。

函数接口定义：
double calc_pow( double x, int n );

函数calc_pow应返回x的n次幂的值。建议用递归实现。题目保证结果在双精度范围内。

输入样例：
2 3

输出样例：
8
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

double calc_pow(double x, int n);

int main(void)
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.0f\n", calc_pow(x, n));

	return 0;
}

double calc_pow(double x, int n)
{
    if (n == 1)
        return x;
    else return x * calc_pow(x, n - 1);
}