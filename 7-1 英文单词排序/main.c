#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ���д������������Ӣ�ĵ��ʣ�����Щ���ʰ����ȴ�С�����������������������ͬ�����������˳�򲻱䡣

�����ʽ��
����Ϊ����Ӣ�ĵ��ʣ�ÿ��һ������#��Ϊ���������־������Ӣ�ĵ�������������20����Ӣ�ĵ���Ϊ����С��10�Ľ���СдӢ����ĸ��ɵ��ַ�����

�����ʽ��
���Ϊ�����Ľ����ÿ�����ʺ��涼�������һ���ո�

����������
blue
red
yellow
green
purple
#

���������
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
	int n; //���ʵĸ���

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