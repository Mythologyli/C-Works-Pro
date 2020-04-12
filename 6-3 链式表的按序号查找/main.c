#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现一个函数，找到并返回链式表的第K个元素。

函数接口定义：
ElementType FindKth( List L, int K );

其中List结构定义如下：
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;
L是给定单链表，函数FindKth要返回链式表的第K个元素。如果该元素不存在，则返回ERROR。

输入样例：
1 3 4 5 2 -1
6
3 6 1 5 4 2

输出样例：
4 NA 1 2 5 3
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read();

ElementType FindKth(List L, int K);

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if (X != ERROR)
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

List Read()
{
    List head = NULL, tail = NULL, p;
    ElementType Data;

    scanf("%d", &Data);
    while (Data != -1)
    {
        p = (List)malloc(sizeof(List));
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

ElementType FindKth(List L, int K)
{
    List p = L;
    
    for (int i = 1; ; i++)
    {
        
        if (p == NULL)
        {
            return ERROR;
        }
        else if (i == K)
        {
            return p->Data;
        }
        
        p = p->Next;
    }
}