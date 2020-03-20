#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个函数，对给定的一个字符串和两个字符，打印出给定字符串中从与第一个字符匹配的位置开始到与第二个字符匹配的位置之间的所有字符。

函数接口定义：
char *match( char *s, char ch1, char ch2 );
函数match应打印s中从ch1到ch2之间的所有字符，并且返回ch1的地址。

输入样例1：
program
r g

输出样例1：
rog
rogram

输入样例2：
program
z o

输出样例2：
(空行)
(空行)

输入样例3：
program
g z

输出样例3：
gram
gram
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
#define MAXS 10

char* match(char* s, char ch1, char ch2);

int main(void)
{
    char str[MAXS], ch_start, ch_end, * p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

	return 0;
}

char* match(char* s, char ch1, char ch2)
{
    char* p_1, * p_2; //ch1, ch2在字符串中的位置;

    //首先搜索字符串中有无ch1
    for (p_1 = s; *p_1 != '\0'; p_1++)
        if (*p_1 == ch1) break;

    //若无，打印空行
    if (*p_1 == '\0')
        putchar('\n');
    //若有，搜索字符串中有无ch2
    else
    {
        for (p_2 = s; *p_2 != '\0'; p_2++)
            if (*p_2 == ch2) break;

        //若无，打印ch1到末尾的内容
        if (*p_2 == '\0')
            printf("%s\n", p_1);
        //若有，打印ch1到ch2的内容
        else
        {
            for (char* p = p_1; p != p_2; p++)
                putchar(*p);
            printf("%c\n", *p_2);
        }
    }

    return p_1;
}