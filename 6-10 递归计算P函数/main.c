#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现下列函数P(n,x)的计算

函数接口定义：
double P( int n, double x );

其中n是用户传入的非负整数，x是双精度浮点数。函数P返回P(n,x)函数的相应值。题目保证输入输出都在双精度范围内。

输入样例：
10 1.7

输出样例：
3.05
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

double P(int n, double x);

int main(void)
{
    int n;
    double x;

    scanf("%d %lf", &n, &x);
    printf("%.2f\n", P(n, x));

    return 0;
}

double P(int n, double x)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else
    {
        return ((2 * n - 1) * P(n - 1, x) - (n - 1) * P(n - 2, x)) / n;
    }
}