#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ���дһ�����ܲ�ͷʫ�ĳ���

�����ʽ��
����Ϊһ�����Ĳ�ͷʫ��һ���ľ䣬ÿ��һ�С�ע�⣺һ������ռ�����ֽڡ�

�����ʽ��
ȡ��ÿ��ĵ�һ�����ֲ�������һ���γ�һ���ַ����������ͬʱ��ĩβ����һ�����з���

����������
һҶ��������
��������������
���˱̲�΢����
˳ˮ�δ��ſ���

���������
һ����˳
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