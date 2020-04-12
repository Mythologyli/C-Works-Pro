#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ����ʽ��Ĳ�������

�����ӿڶ��壺
Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

����List�ṹ�������£�
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

�������������Ķ���Ϊ��
Position Find( List L, ElementType X )���������Ա����״γ���X��λ�á����Ҳ����򷵻�ERROR��
List Insert( List L, ElementType X, Position P )����X������λ��Pָ��Ľ��֮ǰ����������ı�ͷ���������Pָ��Ƿ�λ�ã����ӡ��Wrong Position for Insertion��������ERROR��
List Delete( List L, Position P )����λ��P��Ԫ��ɾ������������ı�ͷ��������Pָ��Ƿ�λ�ã����ӡ��Wrong Position for Deletion��������ERROR��

����������
6
12 2 4 87 10 2
4
2 12 87 5

���������
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

    if (L == P) //��ͷ���ǰ����
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
