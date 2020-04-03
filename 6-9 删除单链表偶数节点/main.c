#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中偶数值的结点删除。链表结点定义如下：
struct ListNode {
    int data;
    struct ListNode *next;
};

函数接口定义：
struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
函数createlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
函数deleteeven将单链表head中偶数值的结点删除，返回结果链表的头指针。

输入样例：
1 2 2 3 4 5 6 7 -1

输出样例：
1 3 5 7
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createlist();
struct ListNode* deleteeven(struct ListNode* head);

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
    head = deleteeven(head);
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

struct ListNode* deleteeven(struct ListNode* head)
{
    struct ListNode* p_1, * p_2;

    while (head != NULL && head->data % 2 == 0)
    {
        p_2 = head;
        head = head->next;
        free(p_2);
    }

    if (head == NULL)
        return NULL;

    p_1 = head;
    p_2 = p_1->next;
    while (p_2 != NULL)
    {
        if (p_2->data % 2 == 0)
        {
            p_1->next = p_2->next;
            free(p_2);
        }
        else p_1 = p_2;

        p_2 = p_1->next;
    }

    return head;
}
