#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求编写程序，输入若干英文单词，对这些单词按长度从小到大排序后输出。如果长度相同，按照输入的顺序不变。

输入格式：
输入为若干英文单词，每行一个，以#作为输入结束标志。其中英文单词总数不超过20个，英文单词为长度小于10的仅由小写英文字母组成的字符串。

输出格式：
输出为排序后的结果，每个单词后面都额外输出一个空格。

输入样例：
blue
red
yellow
green
purple
#

输出样例：
red blue green yellow purple
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

int main(void)
{
	char* word[21] = { NULL };
	char* temp;
	int n; //单词的个数

	for (int i = 0; ; i++)
	{
		word[i] = (char*)malloc(sizeof(char) * 11);
		scanf("%s", word[i]);

		if (strcmp(word[i], "#") == 0)
		{
			n = i;
			break;
		}
	}


	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
			if (strlen(word[j]) > strlen(word[j + 1]))
			{
				temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}
	}

	for (int i = 0; i < n; i++)
		printf("%s ", word[i]);

	return 0;
}