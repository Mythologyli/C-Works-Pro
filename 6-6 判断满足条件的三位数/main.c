#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个函数，统计给定区间内的三位数中有两位数字相同的完全平方数（如144、676）的个数。

函数接口定义：
int search( int n );

其中传入的参数int n是一个三位数的正整数（最高位数字非0）。函数search返回[101, n]区间内所有满足条件的数的个数。

输入样例：
500

输出样例：
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
			if (sqrt(i) == (int)sqrt(i)) //判断是否为完全平方数
			{
				char num[4] = { 0 };
				sprintf(num, "%d", i);
				if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) //判断是否有相等数字
					count++;
			}
		}

		return count;
	}
}