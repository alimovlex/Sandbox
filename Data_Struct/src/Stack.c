#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#define _STACK_ARRAY_H_
#define SIZE_STACK_ARRAY 100
typedef struct
{
	int buf[SIZE_STACK_ARRAY];						
	unsigned uk;													
} StackArray;
static const int okStackArray = 0;
static const int fullStackArray = 1;
static const int emptyStackArray = 2;
static int errorStackArray;

void initStackArray(StackArray *S) 
{
	S->uk = 0;
	errorStackArray = okStackArray;
}

void putStackArray(StackArray *S, int E) 
{
	
	if (isFullStackArray(S)) 
	{
		return;
	}
	
	S->buf[S->uk] = E;				
	S->uk++;							 	
}

void getStackArray(StackArray *S, int *E) 
{
	
	if (isEmptyStackArray(S)) 
	{
		return;
	}
	
	*E = S->buf[S->uk - 1];		
	S->uk--;							 	
}

int isFullStackArray(StackArray *S) 
{
	if (S->uk == SIZE_STACK_ARRAY) 
	{
		errorStackArray = fullStackArray;
		return 1;
	}
	return 0;
}

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
