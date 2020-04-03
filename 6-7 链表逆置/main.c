#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ�������������������������ã�����ͷ��Ϊ��β����β��Ϊ��ͷ�������㶨�����£�
struct ListNode {
    int data;
    struct ListNode *next;
};

�����ӿڶ��壺
struct ListNode *reverse( struct ListNode *head );
����head���û�����������ͷָ�룻����reverse������head���ã������ؽ�������ͷָ�롣

����������
1 2 3 4 5 6 -1

���������
6 5 4 3 2 1
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createlist();
struct ListNode* reverse(struct ListNode* head);

void printlist(struct ListNode* head)
{
    struct ListNode* p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* head;

    head = createlist();
    head = reverse(head);
    printlist(head);

    return 0;
}

struct ListNode* createlist()
{
    struct ListNode* head = NULL, * tail = NULL, * p;
    int data;

    scanf("%d", &data);
    while (data != -1)
    {
        p = (struct ListNode*) malloc(sizeof(struct ListNode));
        p->data = data;
        p->next = NULL;

        if (head == NULL)
            head = p;
        else tail->next = p;
        tail = p;

        scanf("%d", &data);
    }

    return head;
}

struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* new_head = NULL, * new_tail = NULL, * new_p;
    struct ListNode* p = head;

    for (; p != NULL; p = p->next)
    {
        new_p = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_p->data = p->data;
        new_p->next = NULL;

        if (new_tail == NULL)
            new_tail = new_p;
        else new_p->next = new_head;
        new_head = new_p;
    }

    return new_head;
}