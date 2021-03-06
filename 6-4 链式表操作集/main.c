#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
本题要求实现链式表的操作集。

函数接口定义：
Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

其中List结构定义如下：
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

各个操作函数的定义为：
Position Find( List L, ElementType X )：返回线性表中首次出现X的位置。若找不到则返回ERROR；
List Insert( List L, ElementType X, Position P )：将X插入在位置P指向的结点之前，返回链表的表头。如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回ERROR；
List Delete( List L, Position P )：将位置P的元素删除并返回链表的表头。若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回ERROR。

输入样例：
6
12 2 4 87 10 2
4
2 12 87 5

输出样例：
2 is found and deleted.
12 is found and deleted.
87 is found and deleted.
Finding Error: 5 is not in.
5 is inserted as the last element.
Wrong Position for Insertion
Wrong Position for Deletion
10 4 2 5
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR)
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if (L == ERROR) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    for (P = L; P; P = P->Next) printf("%d ", P->Data);
    return 0;
}

Position Find(List L, ElementType X)
{
    List p;

    for (p = L; p != NULL; p = p->Next)
    {
        if (p->Data == X)
        {
            return p;
        }
    }

    return ERROR;
}

List Insert(List L, ElementType X, Position P)
{
    List ptr, new;

    if (L == P) //在头结点前插入
    {
        new = (Position)malloc(sizeof(struct LNode));

        new->Data = X;
        new->Next = L;

        return new;
    }
    else
    {
        for (ptr = L; ptr != NULL; ptr = ptr->Next)
        {
            if (ptr->Next == P)
            {
                new = (Position)malloc(sizeof(struct LNode));

                ptr->Next = new;
                new->Data = X;
                new->Next = P;

                return L;
            }
        }
    }

    printf("Wrong Position for Insertion\n");

    return ERROR;
}

List Delete(List L, Position P)
{
    Position ptr;
    
    if (L == P)
    {
        if (L->Next == NULL)
        {
            return NULL;
        }
        else
        {
            return L->Next;
        }
    }
    else
    {
        for (ptr = L; ptr != NULL; ptr = ptr->Next)
        {
            if (ptr->Next == P)
            {
                ptr->Next = P->Next;

                free(P);

                return L;
            }
        }
    }

    printf("Wrong Position for Deletion\n");

    return ERROR;
}
