#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求编写一个解密藏头诗的程序。

输入格式：
输入为一首中文藏头诗，一共四句，每句一行。注意：一个汉字占两个字节。

输出格式：
取出每句的第一个汉字并连接在一起形成一个字符串并输出。同时在末尾输入一个换行符。

输入样例：
一叶轻舟向东流
帆稍轻握杨柳手
风纤碧波微起舞
顺水任从雅客流

输出样例：
一帆风顺
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

int main(void)
{
	char* s[4] = { NULL };
	
	for (int i = 0; i < 4; i++)
	{
		s[i] = (char*)malloc(20);
		scanf("%s", s[i]);
	}

	printf("%c%c%c%c%c%c%c%c\n", *s[0], *(s[0] + 1), *s[1], *(s[1] + 1), *s[2], *(s[2] + 1), *s[3], *(s[3] + 1));

	return 0;
}