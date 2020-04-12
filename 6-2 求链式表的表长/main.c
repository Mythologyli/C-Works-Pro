#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个函数，求链式表的表长。

函数接口定义：
int Length( List L );

其中List结构定义如下：
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;
L是给定单链表，函数Length要返回链式表的长度。

输入样例：
1 3 4 5 2 -1

输出样例：
5
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read();

int Length(List L);

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

List Read()
{
    List head = NULL, tail = NULL, p;
    ElementType Data;

    scanf("%d", &Data);
    while (Data != -1)
    {
        p = (List) malloc(sizeof(List));
        p->Data = Data;
        p->Next = NULL;

        if (head == NULL)
            head = p;
        else tail->Next = p;
        tail = p;

        scanf("%d", &Data);
    }

    return head;
}

int Length(List L)
{
    int length = 0;

    for (List p = L; p != NULL; p = p->Next)
    {
        length++;
    }

    return length;
}