#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个函数，将给定单向链表逆置，即表头置为表尾，表尾置为表头。链表结点定义如下：
struct ListNode {
    int data;
    struct ListNode *next;
};

函数接口定义：
struct ListNode *reverse( struct ListNode *head );
其中head是用户传入的链表的头指针；函数reverse将链表head逆置，并返回结果链表的头指针。

输入样例：
1 2 3 4 5 6 -1

输出样例：
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