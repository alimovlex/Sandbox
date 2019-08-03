#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include "Stack.h"


struct comp //��������� � ��������� comp(�� ����� component)
{
	int Data; //�����-�� ������(����� ���� ������, � ������� ����� �������� int key; char Data; ���-�� ����� �������� ��� �����-���� ������)
	struct comp *next;//��������� ���� comp �� ��������� �������
};

/*���������� ������*/
int errorStackArray;
/*������������� �����*/
void initStackArray(StackArray *S) 
{
	S->uk = 0;
	errorStackArray = okStackArray;
}
/*��������� � ����*/
void putStackArray(StackArray *S, int E) 
{
	/*���� ���� ����������*/
	if (isFullStackArray(S)) 
	{
		return;
	}
	/*�����*/
	S->buf[S->uk] = E;				// ��������� ��������
	S->uk++;							 	// ����� ���������
}
/*���������� �� �����*/
void getStackArray(StackArray *S, int *E) 
{
	/*���� ���� ����*/
	if (isEmptyStackArray(S)) 
	{
		return;
	}
	/*�����*/
	*E = S->buf[S->uk - 1];		// ���������� �������� � ����������
	S->uk--;							 	// ����� ���������
}
/*��������: ����� �� ����*/
int isFullStackArray(StackArray *S) 
{
	if (S->uk == SIZE_STACK_ARRAY) 
	{
		errorStackArray = fullStackArray;
		return 1;
	}
	return 0;
}
/*��������: ���� �� ����*/
int isEmptyStackArray(StackArray *S) 
{
	if (S->uk == 0) 
	{
		errorStackArray = emptyStackArray;
		return 1;
	}
	return 0;
}
void stack()
{
	/*������������ �����*/
	printf("Array stack\n");
	StackArray S;
	int a;
	initStackArray(&S);
	putStackArray(&S, 10);
	putStackArray(&S, 15);
	printf("Entered: 10, 15\nOutput: ");
	getStackArray(&S, &a);
	printf("%d ", a);
	getStackArray(&S, &a);
	printf("%d\n", a);
}

//---------------------------------------------------habr stack

void s_push(struct comp **top, int D) //������� ���� void(������ �� ����������) ������� ��������� �������� �� ������� ����� � ���������� ������� ����� ������������ � ������
{
	struct comp *q = (struct comp*)malloc(sizeof(struct comp)); //������� ����� ��������� q ���� ��������� comp � �������� ������ ��� ������ ��������
	q->Data = D; //���������� ����������� �����  � Data ��������
	if (top == NULL) //���� ������� ���, �� ���� ���� ������
	{
		*top = q; //�������� ����� ����� ����� �������
	}
	else //���� ���� �� ������
	{
		q->next = *top; //�������� ����� �� ������ ��������, � �������. ������ ������ ������ �� ������� ������.
		*top = q; //����������, ��� �������� ������ �������� ����� �������
	}
}

void s_delete_key(struct comp **top, int N) //������� ������� ��������� ������� top � ����� ������� ����� �������
{
	struct comp *q = *top; //������� ��������� ���� comp � ������������(������) ��� �� ������� �����
	struct comp *prev = NULL;//������� ��������� �� ���������� �������, � ������ �� ����� ������
	while (q != NULL) //���� ��������� q �� ������, �� ����� ��������� ��� � �����, ���� �� ��� �� ������ ���� �������������
	{
		if (q->Data == N)
		{//���� Data �������� ����� �����, ������� ��� ����� �������
			if (q == *top) //���� ����� ��������� ����� �������, �� ���� �������, ������� ��� ����� ������� - �������
			{
				*top = q->next;//����������� ������� �� ��������� �������
				free(q);//������� ������
				q->Data = NULL; //����� �� ��������� ������ �� �������� ���������� � ��������� ������, ��� ��� � ��������� ������������ ��������� ������ ����� ���������� �� NULL ��������, � �������� "������ ������ ����������" ��� �����  "-2738568384" ��� ������, � ����������� �� �����������.
				q->next = NULL;
			}
			else//���� ������� ��������� ��� ��������� ����� ����� ������� ����������
			{
				prev->next = q->next;//�������� ����� �� ����������� �������� � ����������
				free(q);//������� ������ 
				q->Data = NULL;//�������� ����������
				q->next = NULL;
			}
		}// ���� Data �������� �� ����� �����, ������� ��� ����� �������
		prev = q; //���������� ������� ������ ��� ����������
		q = q->next;//���������� ��������� q �� ��������� �������
	}
}

void s_print(struct comp *top) //��������� ��������� �� ������� �����	
{ 	
	struct comp *q = top; //������������� q �� �������
	while (q) //���� q �� ������ (while(q) ������������ while(q != NULL))
	{ 
		printf_s("%i", q->Data);//������� �� ����� ������ ������ �����
		q = q->next;//����� ���� ��� ������ ����������� q �� ��������� �������(������)
	}
	printf("\n");
}

void habrostack()
{
	printf("Habrostack initial value\n");
	struct comp *top = NULL; //� ������ ��������� � ��� ��� �������, �������������� ������� ���, ���� �� �������� NULL
					  //������ �������� ��������� ����� �� 1 �� 5 � ��� ����
	s_push(&top, 1);
	s_push(&top, 2);
	s_push(&top, 3);
	s_push(&top, 4);
	s_push(&top, 5);
	//����� ���������� ������� � ����� � ��� ����� 54321
	s_print(top);//�������
	s_delete_key(&top, 4); //����� ������� 4, � ����� ���������� 5321
	printf("After deletion\n");
	s_print(top);//�������
}