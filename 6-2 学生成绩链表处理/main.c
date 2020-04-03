#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
����Ҫ��ʵ������������һ���������ѧ���ɼ���֯�ɵ���������һ�����ɼ�����ĳ�����ߵ�ѧ������������ɾ����

�����ӿڶ��壺
struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

����createlist����scanf�������л�ȡѧ������Ϣ��������֯�ɵ�����������������ͷָ�롣����ڵ�ṹ�������£�
struct stud_node {
    int              num;      //ѧ��
    char             name[20]; //����
    int              score;    //�ɼ�
    struct stud_node* next;    //ָ���¸�����ָ��
};

����Ϊ���ɸ�ѧ������Ϣ��ѧ�š��������ɼ�����������ѧ��Ϊ0ʱ������

����deletelist����headΪͷָ���������ɾ���ɼ�����min_score��ѧ���������ؽ�������ͷָ�롣

����������
1 zhang 78
2 wang 80
3 li 75
4 zhao 85
0
80

���������
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