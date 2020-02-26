#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个函数，将正整数n转换为二进制后输出。

函数接口定义：
void dectobin(int n);

函数dectobin应在一行中打印出二进制的n。建议用递归实现。

输入样例：
10

输出样例：
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