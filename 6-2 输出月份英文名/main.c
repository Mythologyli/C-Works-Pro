#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ�ֺ��������Է���һ�������·ݵ�Ӣ�����ơ�

�����ӿڶ��壺
char *getmonth( int n );
����getmonthӦ���ش洢��n��Ӧ���·�Ӣ�����Ƶ��ַ���ͷָ�롣�������Ĳ���n����һ�������·ݵ����֣��򷵻ؿ�ָ��NULL��

��������1��
5

�������1��
May

��������2��
15

�������2��
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