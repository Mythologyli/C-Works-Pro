#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ���������ҵ���������ʽ��ĵ�K��Ԫ�ء�

�����ӿڶ��壺
ElementType FindKth( List L, int K );

����List�ṹ�������£�
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;
L�Ǹ�������������FindKthҪ������ʽ��ĵ�K��Ԫ�ء������Ԫ�ز����ڣ��򷵻�ERROR��

����������
1 3 4 5 2 -1
6
3 6 1 5 4 2

���������
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