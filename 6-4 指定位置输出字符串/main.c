#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ���������Ը�����һ���ַ����������ַ�����ӡ�������ַ����д����һ���ַ�ƥ���λ�ÿ�ʼ����ڶ����ַ�ƥ���λ��֮��������ַ���

�����ӿڶ��壺
char *match( char *s, char ch1, char ch2 );
����matchӦ��ӡs�д�ch1��ch2֮��������ַ������ҷ���ch1�ĵ�ַ��

��������1��
program
r g

�������1��
rog
rogram

��������2��
program
z o

�������2��
(����)
(����)

��������3��
program
g z

�������3��
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
    char* p_1, * p_2; //ch1, ch2���ַ����е�λ��;

    //���������ַ���������ch1
    for (p_1 = s; *p_1 != '\0'; p_1++)
        if (*p_1 == ch1) break;

    //���ޣ���ӡ����
    if (*p_1 == '\0')
        putchar('\n');
    //���У������ַ���������ch2
    else
    {
        for (p_2 = s; *p_2 != '\0'; p_2++)
            if (*p_2 == ch2) break;

        //���ޣ���ӡch1��ĩβ������
        if (*p_2 == '\0')
            printf("%s\n", p_1);
        //���У���ӡch1��ch2������
        else
        {
            for (char* p = p_1; p != p_2; p++)
                putchar(*p);
            printf("%c\n", *p_2);
        }
    }

    return p_1;
}