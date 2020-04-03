#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个将输入的学生成绩组织成单向链表的简单函数。

函数接口定义：
void input();

该函数利用scanf从输入中获取学生的信息，并将其组织成单向链表。链表节点结构定义如下：
struct stud_node {
    int num;                //学号
    char name[20];          //姓名
    int score;              //成绩
    struct stud_node* next; //指向下个结点的指针
};
单向链表的头尾指针保存在全局变量head和tail中。
输入为若干个学生的信息（学号、姓名、成绩），当输入学号为0时结束。

输入样例：
1 zhang 78
2 wang 80
3 li 75
4 zhao 85
0

输出样例：
1 zhang 78
2 wang 80
3 li 75
4 zhao 85
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
    int    num;
    char   name[20];
    int    score;
    struct stud_node* next;
};
struct stud_node* head, * tail;

void input();

int main(void)
{
    struct stud_node* p;

    head = tail = NULL;
    input();
    for (p = head; p != NULL; p = p->next)
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

void input()
{
    struct stud_node* p;
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
}