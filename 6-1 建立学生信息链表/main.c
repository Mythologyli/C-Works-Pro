#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ��һ���������ѧ���ɼ���֯�ɵ�������ļ򵥺�����

�����ӿڶ��壺
void input();

�ú�������scanf�������л�ȡѧ������Ϣ����������֯�ɵ�����������ڵ�ṹ�������£�
struct stud_node {
    int num;                //ѧ��
    char name[20];          //����
    int score;              //�ɼ�
    struct stud_node* next; //ָ���¸�����ָ��
};
���������ͷβָ�뱣����ȫ�ֱ���head��tail�С�
����Ϊ���ɸ�ѧ������Ϣ��ѧ�š��������ɼ�����������ѧ��Ϊ0ʱ������

����������
1 zhang 78
2 wang 80
3 li 75
4 zhao 85
0

���������
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