#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ���������������ַ�������������

�����ӿڶ��壺
char *str_cat( char *s, char *t );
����str_catӦ���ַ���t���Ƶ��ַ���s��ĩ�ˣ����ҷ����ַ���s���׵�ַ��

����������
abc
def

���������
abcdef
abcdef
*/

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
#define MAXS 10

char* str_cat(char* s, char* t);

int main(void)
{
    char* p;
    char str1[MAXS + MAXS] = { '\0' }, str2[MAXS] = { '\0' };

    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);

	return 0;
}

char* str_cat(char* s, char* t)
{
    return strcat(s, t);
}