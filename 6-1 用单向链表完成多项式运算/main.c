#define _CRT_SECURE_NO_WARNINGS
/*��ֹʹ��scanf()�Ⱥ���ʱ����*/

/*
������������ʽ���������ǵļӡ������˷��� ���������������Ļ�ϡ�

1�����룺�Ӽ��̷����зֱ�������������ʽ���ݣ�ÿ������ʽ�����ʽ���£�
n a1 m1 a2 m2 a3 m3 . .. ai mi.... an mn
����nΪ��aiΪ����ʽϵ��Ϊ���������ϵ����miΪָ��, ���Ƕ������������������������Ķ���ʽ����Ϊ(���з���^��ʾ�ݴ�)��
a1x^m1 + a2x^m2 + a3x^m3 + ...... + an x^mn

2�����������������������������ʽ�� Ȼ��������ǵ�����������ʽΪ��
A=
B=
A+B=
A-B=
A*B=
Ҫ�󣺶���ʽ���ʱ���ݴ����ߵ��͵�˳��������������κ�һ���ϵ����0�Ļ����벻Ҫ������������е�ϵ��Ϊ0�������0��

�����ӿڶ��壺
void print_polynomial(polynomial *head);
���������һ������ʽ���������ĿҪ��Ĺ����Լ������������漰������ʽ����Ĵ����Լ�����ʽ�ӡ����ͳ˷���������Ĺ���ģ�����ڱ�����ʵ��֮ǰһ��������ɣ�������������ں��ʵ�λ�á�

����������
���������һ�����롣���磺
3 1 2 3 4 5 6
3 1 2 3 4 5 6

���������
�����������Ӧ�����������(���� x ��Сд��ĸ)��
A=5x^6+3x^4+x^2
B=5x^6+3x^4+x^2
A+B=10x^6+6x^4+2x^2
A-B=0
A*B=25x^12+30x^10+19x^8+6x^6+x^4
*/

#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

typedef struct node
{
	int coef;             /* ϵ�� */
	int exp;              /* ָ�� */
	struct node* next;
} polynomial;

polynomial* create_polynomial();
polynomial* add_polynomial(polyA, polyB);
polynomial* subtract_polynomial(polyA, polyB);
polynomial* multiply_polynomial(polyA, polyB);
void print_polynomial(polynomial* head);

int main(void)
{
	polynomial* polyA, * polyB;

	polyA = create_polynomial();  /* ���к���create_polynomial()���ڶ��벢��������ʽA������*/
	polyB = create_polynomial();  /* ���벢��������ʽB������ */
	printf("A=");
	print_polynomial(polyA);   /* �������ʽA */
	printf("B=");
	print_polynomial(polyB);  /* �������ʽB */
	printf("A+B=");
	print_polynomial(add_polynomial(polyA, polyB));
	/* �������ʽ��A+B �Ľ��, ���к���add_polynomial(polyA,polyB)������A+B�Ķ���ʽ*/
	printf("A-B=");
	print_polynomial(subtract_polynomial(polyA, polyB));
	/* �������ʽ��A-B �Ľ�������к���subtract_polynomial(polyA,polyB)����A-B�Ķ���ʽ*/
	printf("A*B=");
	print_polynomial(multiply_polynomial(polyA, polyB));
	/* �������ʽ��A*B �Ľ�������к���multiply_polynomial(polyA,polyB)����A*B�Ķ���ʽ*/

	return 0;
}

/*���������ʽʱ�������򣬷����������*/
polynomial* create_polynomial()
{
	int n; //����
	polynomial* head = NULL,
		      * input,//������
		      * p;    //�ƶ�ָ��

	scanf("%d", &n);

	if (n == 0) //����ʽΪ0
	{
		head = (polynomial*)malloc(sizeof(polynomial));
		head->coef = 0;
		head->exp = 0;
		head->next = NULL;
	}
	else //����ʽ��Ϊ0�����벢����
	{
		for (int i = 1; i <= n; i++) 
		{
			polynomial* input = (polynomial*)malloc(sizeof(polynomial));
			scanf("%d%d", &input->coef, &input->exp);

			if (head == NULL) //��ͷ���Ϊ�գ�inputΪͷ���
			{
				head = input;
				head->next = NULL;
			}
			else if (input->exp > head->exp) //��inputָ����ͷ���󣬽���ͷ���ǰ
			{
				input->next = head;
				head = input;
			}
			else if (input->exp == head->exp) //��inputָ����ͷ�����ȣ�ϵ�����
			{
				head->coef += input->coef;
				free(input); //�ͷ�input
			}
			else //��inputָ����ͷ���С
			{
				for (p = head; ; p = p->next)
				{
					if (p->next == NULL) //��pΪβ�ڵ㣬��input����p��
					{
						p->next = input;
						input->next = NULL;
						break;
					}
					else if (input->exp > p->next->exp) //��input����p��p->next֮��
					{
						input->next = p->next;
						p->next = input;
						break;
					}
					else if (input->exp == p->exp) //ָ�����,ϵ�����
					{
						p->next->coef += input->coef;
						free(input); //�ͷ�input
						break;
					}
				}
			}
		}
	}

	return head;
}

/*������������Ķ���ʽ���*/
polynomial* add_polynomial(polynomial* polyA, polynomial* polyB)
{
	/*����Ķ���ʽ*/
	polynomial* pA = polyA, //A���ƶ�ָ��
		      * pB = polyB; //B���ƶ�ָ��

	/*����Ķ���ʽ*/
	polynomial* head = NULL,
		      * tail = NULL,
		      * p; //�ƶ�ָ��
	
	while (pA != NULL || pB!= NULL)
	{
		p = (polynomial*)malloc(sizeof(polynomial));

		if ((pA != NULL && pB == NULL) || (pA != NULL && pA->exp > pB->exp))
		{
			p->coef = pA->coef;
			p->exp = pA->exp;
			p->next = NULL;
			
			pA = pA->next;
		}
		else if ((pA == NULL && pB != NULL) || (pB != NULL && pA->exp < pB->exp))
		{
			p->coef = pB->coef;
			p->exp = pB->exp;
			p->next = NULL;

			pB = pB->next;
		}
		else
		{
			p->coef = pA->coef + pB->coef;
			p->exp = pA->exp;
			p->next = NULL;

			pA = pA->next;
			pB = pB->next;
		}

		if (head == NULL)
		{
			head = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;
	}

	return head;
}

/*������������Ķ���ʽ���*/
polynomial* subtract_polynomial(polynomial* polyA, polynomial* polyB)
{
	/*����Ķ���ʽ*/
	polynomial* pA = polyA, //A���ƶ�ָ��
		      * pB = polyB; //B���ƶ�ָ��

    /*����Ķ���ʽ*/
	polynomial* head = NULL,
		      * tail = NULL,
		      * p; //�ƶ�ָ��

	while (pA != NULL || pB != NULL)
	{
		p = (polynomial*)malloc(sizeof(polynomial));

		if ((pA != NULL && pB == NULL) || (pA != NULL && pA->exp > pB->exp))
		{
			p->coef = pA->coef;
			p->exp = pA->exp;
			p->next = NULL;

			pA = pA->next;
		}
		else if ((pA == NULL && pB != NULL) || (pB != NULL && pA->exp < pB->exp))
		{
			p->coef = -pB->coef;
			p->exp = pB->exp;
			p->next = NULL;

			pB = pB->next;
		}
		else
		{
			p->coef = pA->coef - pB->coef;
			p->exp = pA->exp;
			p->next = NULL;

			pA = pA->next;
			pB = pB->next;
		}

		if (head == NULL)
		{
			head = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;
	}

	return head;
}

/*������������Ķ���ʽ��ˣ�ʹ�õݹ�ķ���*/
polynomial* multiply_polynomial(polynomial* polyA, polynomial* polyB)
{
	polynomial* head = (polynomial*)malloc(sizeof(polynomial));

	if (polyA->next == NULL
     && polyB->next == NULL) //A��B��Ϊ����
	{
		head->coef = polyA->coef * polyB->coef;
		head->exp = polyA->exp + polyB->exp;
		head->next = NULL;
	}
	else
	{
		head->coef = 0;
		head->exp = 0;
		head->next = NULL;

		if (polyA->next != NULL) //A��Ϊ����
		{
			for (polynomial* p = polyA; p != NULL; p = p->next)
			{
				polynomial* temp = (polynomial*)malloc(sizeof(polynomial)); //tempΪA��ĳһ��
				temp->coef = p->coef;
				temp->exp = p->exp;
				temp->next = NULL;

				head = add_polynomial(head, multiply_polynomial(temp, polyB));

				free(temp);
			}
		}
		else //AΪ���B��Ϊ����
		{
			for (polynomial* p = polyB; p != NULL; p = p->next)
			{
				polynomial* temp = (polynomial*)malloc(sizeof(polynomial)); //tempΪB��ĳһ��
				temp->coef = p->coef;
				temp->exp = p->exp;
				temp->next = NULL;
				
				head = add_polynomial(head, multiply_polynomial(polyA, temp));

				free(temp);
			}
		}
	}

	return head;
}

/*�������������Ķ���ʽ*/
void print_polynomial(polynomial* head)
{
	_Bool all_zero = 1; //Ĭ������ȫΪ0
	polynomial* p; //�ƶ�ָ��

	for (p = head; p != NULL; p = p->next)
	{
		if (p->coef == 0) //ϵ��Ϊ0
		{
			continue;
		}
		else
		{
			if (p->coef > 0) //ϵ��Ϊ��
			{
				if (all_zero == 1)
				{
					all_zero = 0;
				}
				else //�ǵ�һ����+
				{
					printf("+");
				}
				
				if (p->coef == 1 && p->exp == 0) //��ֵΪ1������1
				{
					printf("1");
				}
				if (p->coef != 1) //ϵ��Ϊ���Ҳ�Ϊ1
				{
					printf("%d", p->coef);
				}
			}
			else if (p->coef < 0) //ϵ��Ϊ��
			{
				if (all_zero == 1)
				{
					all_zero = 0;
				}

				if (p->coef == -1) //ϵ��Ϊ-1
				{
					if (p->exp == 0) //��ֵΪ-1������-1
					{
						printf("-1");
					}
					else //ϵ��Ϊ-1��ֵ��Ϊ0
					{
						printf("-");
					}
				}
				else //ϵ��Ϊ���Ҳ�Ϊ-1
				{
					printf("%d", p->coef);
				}
			}
		}
		
		if (p->exp != 0) //ָ����Ϊ0
		{
			if (p->exp == 1) //ָ��Ϊ1
			{
				printf("x");
			}
			else
			{
				printf("x^%d", p->exp);
			}
		}
	}

	if (all_zero == 1)
	{
		printf("0"); //�������ȫΪ0�����0
	}

	printf("\n");
}