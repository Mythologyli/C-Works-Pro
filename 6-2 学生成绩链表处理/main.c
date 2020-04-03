#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现两个函数，一个将输入的学生成绩组织成单向链表；另一个将成绩低于某分数线的学生结点从链表中删除。

函数接口定义：
struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

函数createlist利用scanf从输入中获取学生的信息，将其组织成单向链表，并返回链表头指针。链表节点结构定义如下：
struct stud_node {
    int              num;      //学号
    char             name[20]; //姓名
    int              score;    //成绩
    struct stud_node* next;    //指向下个结点的指针
};

输入为若干个学生的信息（学号、姓名、成绩），当输入学号为0时结束。

函数deletelist从以head为头指针的链表中删除成绩低于min_score的学生，并返回结果链表的头指针。

输入样例：
1 zhang 78
2 wang 80
3 li 75
4 zhao 85
0
80

输出样例：
2 wang 80
4 zhao 85
*/

#include <stdio.h>
#include <stdlib.h>

struct stud_node {
    int    num;
    char   name[20];
    int    score;
    struct stud_node* next;
};

struct stud_node* createlist();
struct stud_node* deletelist(struct stud_node* head, int min_score);

int main()
{
    int min_score;
    struct stud_node* p, * head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for (p = head; p != NULL; p = p->next)
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

struct stud_node* createlist()
{
    struct stud_node* head = NULL, * tail = NULL, * p;
    int num;

    scanf("%d", &num);    
    while (num != 0)
    {
        p = (struct stud_node*) malloc(sizeof(struct stud_node));
        p->num = num;
        scanf("%s%d", p->name, &p->score);
        p->next = NULL;

        if (head == NULL)
            head = p;
        else tail->next = p;
        tail = p;

        scanf("%d", &num);
    }

    return head;
}

struct stud_node* deletelist(struct stud_node* head, int min_score)
{
    struct stud_node* p_1, * p_2;

    while (head != NULL && head->score < min_score)
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
        if (p_2->score < min_score)
        {
            p_1->next = p_2->next;
            free(p_2);
        }
        else p_1 = p_2;

        p_2 = p_1->next;
    }

    return head;
}