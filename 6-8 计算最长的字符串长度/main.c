#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ�����������ڼ�����n��Ԫ�ص�ָ������s������ַ����ĳ��ȡ�

�����ӿڶ��壺
int max_len( char *s[], int n );
����n���ַ����洢��s[]�У�����max_lenӦ����������ַ����ĳ��ȡ�

����������
4
blue
yellow
red
green

���������
6
*/

#include <stdio.h>
//#include <math.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

#define MAXN 10
#define MAXS 20

int max_len(char* s[], int n);

int main(void)
{
    int i, n;
    char* string[MAXN] = { NULL };

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        string[i] = (char*)malloc(sizeof(char) * MAXS);
        scanf("%s", string[i]);
    }
    printf("%d\n", max_len(string, n));


	return 0;
}

int max_len(char* s[], int n)
{
    int max = strlen(s[0]);

    for (int i = 1; i < n; i++)
        if (strlen(s[i]) > max) max = strlen(s[i]);

    return max;
}