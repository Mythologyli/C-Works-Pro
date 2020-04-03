#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个合并两个有序链表的简单函数。链表结点定义如下：
struct ListNode {
    int data;
    struct ListNode *next;
};

函数接口定义：
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
其中list1和list2是用户传入的两个按data升序链接的链表的头指针；函数mergelists将两个链表合并成一个按data升序链接的链表，并返回结果链表的头指针。

输入样例：
1 3 5 7 -1
2 4 6 -1

输出样例：
1 2 3 4 5 6 7
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createlist();
struct ListNode* mergelists(struct ListNode* list1, struct ListNode* list2);

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
    struct ListNode* list1, * list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);

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

struct ListNode* mergelists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* mergelists(struct ListNode* list1, struct ListNode* list2);
    {
        struct ListNode* head = NULL, * tail = NULL, * p, * p_1 = list1, * p_2 = list2;
        int min;

        if (p_1 != NULL)
        {
            if (p_2 != NULL)
            {
                if (p_1->data <= p_2->data)
                {
                    min = p_1->data;
                    p_1 = p_1->next;
                }
                else
                {
                    min = p_2->data;
                    p_2 = p_2->next;
                }
            }
            else
            {
                min = p_1->data;
                p_1 = p_1->next;
            }
        }
        else if (p_2 != NULL)
        {
            min = p_2->data;
            p_2 = p_2->next;
        }
        else return NULL;

        while (1)
        {
            p = (struct ListNode*)malloc(sizeof(struct ListNode));
            p->data = min;
            p->next = NULL;

            if (head == NULL)
                head = p;
            else tail->next = p;
            tail = p;

            if (p_1 != NULL)
            {
                if (p_2 != NULL)
                {
                    if (p_1->data <= p_2->data)
                    {
                        min = p_1->data;
                        p_1 = p_1->next;
                    }
                    else
                    {
                        min = p_2->data;
                        p_2 = p_2->next;
                    }
                }
                else
                {
                    min = p_1->data;
                    p_1 = p_1->next;
                }
            }
            else if (p_2 != NULL)
            {
                min = p_2->data;
                p_2 = p_2->next;
            }
            else break;
        }

        return head;
    }
}