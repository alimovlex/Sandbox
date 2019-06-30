#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif
#ifndef _STACK_ARRAY_H_
#define _STACK_ARRAY_H_
/*������ �����*/
#define SIZE_STACK_ARRAY 100
typedef struct
{
	int buf[SIZE_STACK_ARRAY];						// ����� �����
	unsigned uk;													// ���������
} StackArray;
/*�������� �������������� ��������*/
const int okStackArray = 0;// ��� ���������
const int fullStackArray = 1;// ���� ����������
const int emptyStackArray = 2;// ���� ����
/*********************************/
/*���������� ������*/
extern int errorStackArray;
/*������� ��� �����*/
DLL void stack();
/******************/
/*������� ������ �� ������*/
DLL void initStackArray(StackArray *S);									// ������������� �����
DLL void putStackArray(StackArray *S, int E);			// ��������� � ����
DLL void getStackArray(StackArray *S, int *E);			// ���������� �� �����
DLL int isFullStackArray(StackArray *S);								// ��������: ����� �� ����
DLL int isEmptyStackArray(StackArray *S);								// ��������: ���� �� ����
/**************************/
#endif