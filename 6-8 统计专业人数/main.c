#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ��������ͳ��ѧ��ѧ��������רҵΪ�������ѧ�������������㶨�����£�
struct ListNode {
    char code[8];
    struct ListNode *next;
};
����ѧ����ѧ�Ź�7λ���֣����е�2��3λ��רҵ��š������רҵ�ı��Ϊ02��

�����ӿڶ��壺
int countcs( struct ListNode *head );
����head���û������ѧ��ѧ�������ͷָ�룻����countcsͳ�Ʋ�����head������רҵΪ�������ѧ��������

����������
1021202
2022310
8102134
1030912
3110203
4021205
#

���������
3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char code[8];
    struct ListNode* next;
};

struct ListNode* createlist();
int countcs(struct ListNode* head);

int main()
{
    struct ListNode* head;

    head = createlist();
    printf("%d\n", countcs(head));

    return 0;
}

struct ListNode* createlist()
{
    struct ListNode* head = NULL, * tail = NULL, * p;
    char code[8];

    scanf("%s", code);
    while (code[0] != '#')
    {
        p = (struct ListNode*) malloc(sizeof(struct ListNode));
        strcpy(p->code, code);
        p->next = NULL;

        if (head == NULL)
            head = p;
        else tail->next = p;
        tail = p;

        scanf("%s", code);
    }

    return head;
}

int countcs(struct ListNode* head)
{
    struct ListNode* p = head;
    int count = 0;

    for (; p != NULL; p = p->next)
    {
        if (p->code[1] == '0' && p->code[2] == '2')
            count++;
    }

    return count;
}
