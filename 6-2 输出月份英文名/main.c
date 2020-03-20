#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现函数，可以返回一个给定月份的英文名称。

函数接口定义：
char *getmonth( int n );
函数getmonth应返回存储了n对应的月份英文名称的字符串头指针。如果传入的参数n不是一个代表月份的数字，则返回空指针NULL。

输入样例1：
5

输出样例1：
May

输入样例2：
15

输出样例2：
wrong input!
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

char* getmonth(int n);

int main(void)
{
    int n;
    char* s;

    scanf("%d", &n);
    s = getmonth(n);
    if (s == NULL) printf("wrong input!\n");
    else printf("%s\n", s);

	return 0;
}

char* getmonth(int n)
{
    char* month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    
    if (n >= 1 && n <= 12)
        return month[n - 1];
    else return NULL;
}