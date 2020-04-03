#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中奇数值的结点重新组成一个新的链表。链表结点定义如下：
struct ListNode {
    int data;
    ListNode *next;
};

函数接口定义:
struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
函数getodd将单链表L中奇数值的结点分离出来，重新组成一个新的链表。返回指向新链表头结点的指针，同时将L中存储的地址改为删除了奇数值结点后的链表的头结点地址（所以要传入L的指针）。

输入样例：
1 2 2 3 4 5 6 7 -1

输出样例：
1 3 5 7
2 2 4 6
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* readlist();
struct ListNode* getodd(struct ListNode** L);
void printlist(struct ListNode* L)
{
    struct ListNode* p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* L, * Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}

struct ListNode* readlist()
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

struct ListNode* getodd(struct ListNode** L)
{
    struct ListNode* head = *L, * p_1, * p_2;
    struct ListNode* new_head = NULL, * new_tail = NULL, * new_p;

    while (head != NULL && head->data % 2 != 0)
    {
        new_p = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_p->data = head->data;
        new_p->next = NULL;

        if (new_head == NULL)
            new_head = new_p;
        else new_tail->next = new_p;
        new_tail = new_p;
        
        p_2 = head;
        head = head->next;
        free(p_2);
    }

    if (head == NULL)
    {
        *L = NULL;
        return new_head;
    }

    p_1 = head;
    p_2 = p_1->next;
    while (p_2 != NULL)
    {
        if (p_2->data % 2 != 0)
        {
            new_p = (struct ListNode*) malloc(sizeof(struct ListNode));
            new_p->data = p_2->data;
            new_p->next = NULL;

            if (new_head == NULL)
                new_head= new_p;
            else new_tail->next = new_p;
            new_tail = new_p;
            
            p_1->next = p_2->next;
            free(p_2);
        }
        else p_1 = p_2;

        p_2 = p_1->next;
    }

    *L = head;

    return new_head;
}
