#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个函数，统计学生学号链表中专业为计算机的学生人数。链表结点定义如下：
struct ListNode {
    char code[8];
    struct ListNode *next;
};
这里学生的学号共7位数字，其中第2、3位是专业编号。计算机专业的编号为02。

函数接口定义：
int countcs( struct ListNode *head );
其中head是用户传入的学生学号链表的头指针；函数countcs统计并返回head链表中专业为计算机的学生人数。

输入样例：
1021202
2022310
8102134
1030912
3110203
4021205
#

输出样例：
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
