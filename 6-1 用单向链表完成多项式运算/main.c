#define _CRT_SECURE_NO_WARNINGS
/*防止使用scanf()等函数时报错*/

/*
输入两个多项式，计算它们的加、减及乘法， 将计算结果输出到屏幕上。

1）输入：从键盘分两行分别输入两个多项式数据，每个多项式输入格式如下：
n a1 m1 a2 m2 a3 m3 . .. ai mi.... an mn
其中n为，ai为多项式系数为非零的项数系数，mi为指数, 它们都是整数，该输入数据所表达的多项式意义为(其中符号^表示幂次)：
a1x^m1 + a2x^m2 + a3x^m3 + ...... + an x^mn

2）输出：先输出参与运算的两个多项式， 然后输出它们的运算结果，格式为：
A=
B=
A+B=
A-B=
A*B=
要求：多项式输出时从幂次数高到低的顺序逐项输出，若任何一项的系数是0的话，请不要输出，除非所有的系数为0，则输出0。

函数接口定义：
void print_polynomial(polynomial *head);
本函数完成一个多项式的输出。题目要求的功能以及本函数具体涉及到多项式链表的创建以及多项式加、减和乘法运算所需的功能模块请在本函数实现之前一并自行完成，并将代码插入在合适的位置。

输入样例：
在这里给出一组输入。例如：
3 1 2 3 4 5 6
3 1 2 3 4 5 6

输出样例：
在这里给出相应的输出。例如(其中 x 是小写字母)：
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
	int coef;             /* 系数 */
	int exp;              /* 指数 */
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

	polyA = create_polynomial();  /* 其中函数create_polynomial()用于读入并创建多项式A的链表*/
	polyB = create_polynomial();  /* 读入并创建多项式B的链表 */
	printf("A=");
	print_polynomial(polyA);   /* 输出多项式A */
	printf("B=");
	print_polynomial(polyB);  /* 输出多项式B */
	printf("A+B=");
	print_polynomial(add_polynomial(polyA, polyB));
	/* 输出多项式加A+B 的结果, 其中函数add_polynomial(polyA,polyB)将返回A+B的多项式*/
	printf("A-B=");
	print_polynomial(subtract_polynomial(polyA, polyB));
	/* 输出多项式减A-B 的结果，其中函数subtract_polynomial(polyA,polyB)返回A-B的多项式*/
	printf("A*B=");
	print_polynomial(multiply_polynomial(polyA, polyB));
	/* 输出多项式乘A*B 的结果，其中函数multiply_polynomial(polyA,polyB)返回A*B的多项式*/

	return 0;
}

/*在输入多项式时进行排序，方便后续运算*/
polynomial* create_polynomial()
{
	int n; //项数
	polynomial* head = NULL,
		      * input,//输入量
		      * p;    //移动指针

	scanf("%d", &n);

	if (n == 0) //多项式为0
	{
		head = (polynomial*)malloc(sizeof(polynomial));
		head->coef = 0;
		head->exp = 0;
		head->next = NULL;
	}
	else //多项式不为0，输入并排序
	{
		for (int i = 1; i <= n; i++) 
		{
			polynomial* input = (polynomial*)malloc(sizeof(polynomial));
			scanf("%d%d", &input->coef, &input->exp);

			if (head == NULL) //若头结点为空，input为头结点
			{
				head = input;
				head->next = NULL;
			}
			else if (input->exp > head->exp) //若input指数比头结点大，接在头结点前
			{
				input->next = head;
				head = input;
			}
			else if (input->exp == head->exp) //若input指数与头结点相等，系数相加
			{
				head->coef += input->coef;
				free(input); //释放input
			}
			else //若input指数比头结点小
			{
				for (p = head; ; p = p->next)
				{
					if (p->next == NULL) //若p为尾节点，将input接在p后
					{
						p->next = input;
						input->next = NULL;
						break;
					}
					else if (input->exp > p->next->exp) //将input插入p和p->next之间
					{
						input->next = p->next;
						p->next = input;
						break;
					}
					else if (input->exp == p->exp) //指数相等,系数相加
					{
						p->next->coef += input->coef;
						free(input); //释放input
						break;
					}
				}
			}
		}
	}

	return head;
}

/*将两个已排序的多项式相加*/
polynomial* add_polynomial(polynomial* polyA, polynomial* polyB)
{
	/*输入的多项式*/
	polynomial* pA = polyA, //A的移动指针
		      * pB = polyB; //B的移动指针

	/*输出的多项式*/
	polynomial* head = NULL,
		      * tail = NULL,
		      * p; //移动指针
	
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

/*将两个已排序的多项式相减*/
polynomial* subtract_polynomial(polynomial* polyA, polynomial* polyB)
{
	/*输入的多项式*/
	polynomial* pA = polyA, //A的移动指针
		      * pB = polyB; //B的移动指针

    /*输出的多项式*/
	polynomial* head = NULL,
		      * tail = NULL,
		      * p; //移动指针

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

/*将两个已排序的多项式相乘；使用递归的方法*/
polynomial* multiply_polynomial(polynomial* polyA, polynomial* polyB)
{
	polynomial* head = (polynomial*)malloc(sizeof(polynomial));

	if (polyA->next == NULL
     && polyB->next == NULL) //A和B均为单项
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

		if (polyA->next != NULL) //A不为单项
		{
			for (polynomial* p = polyA; p != NULL; p = p->next)
			{
				polynomial* temp = (polynomial*)malloc(sizeof(polynomial)); //temp为A的某一项
				temp->coef = p->coef;
				temp->exp = p->exp;
				temp->next = NULL;

				head = add_polynomial(head, multiply_polynomial(temp, polyB));

				free(temp);
			}
		}
		else //A为单项，B不为单项
		{
			for (polynomial* p = polyB; p != NULL; p = p->next)
			{
				polynomial* temp = (polynomial*)malloc(sizeof(polynomial)); //temp为B的某一项
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

/*处理并输出已排序的多项式*/
void print_polynomial(polynomial* head)
{
	_Bool all_zero = 1; //默认项数全为0
	polynomial* p; //移动指针

	for (p = head; p != NULL; p = p->next)
	{
		if (p->coef == 0) //系数为0
		{
			continue;
		}
		else
		{
			if (p->coef > 0) //系数为正
			{
				if (all_zero == 1)
				{
					all_zero = 0;
				}
				else //非第一项，输出+
				{
					printf("+");
				}
				
				if (p->coef == 1 && p->exp == 0) //有值为1的项，输出1
				{
					printf("1");
				}
				if (p->coef != 1) //系数为正且不为1
				{
					printf("%d", p->coef);
				}
			}
			else if (p->coef < 0) //系数为负
			{
				if (all_zero == 1)
				{
					all_zero = 0;
				}

				if (p->coef == -1) //系数为-1
				{
					if (p->exp == 0) //有值为-1的项，输出-1
					{
						printf("-1");
					}
					else //系数为-1且值不为0
					{
						printf("-");
					}
				}
				else //系数为负且不为-1
				{
					printf("%d", p->coef);
				}
			}
		}
		
		if (p->exp != 0) //指数不为0
		{
			if (p->exp == 1) //指数为1
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
		printf("0"); //如果项数全为0，输出0
	}

	printf("\n");
}