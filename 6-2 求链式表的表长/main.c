#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ������������ʽ��ı���

�����ӿڶ��壺
int Length( List L );

����List�ṹ�������£�
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;
L�Ǹ�������������LengthҪ������ʽ��ĳ��ȡ�

����������
1 3 4 5 2 -1

���������
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