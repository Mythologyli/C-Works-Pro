#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ���ϲ�������������ļ򵥺����������㶨�����£�
struct ListNode {
    int data;
    struct ListNode *next;
};

�����ӿڶ��壺
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
����list1��list2���û������������data�������ӵ������ͷָ�룻����mergelists����������ϲ���һ����data�������ӵ����������ؽ�������ͷָ�롣

����������
1 3 5 7 -1
2 4 6 -1

���������
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