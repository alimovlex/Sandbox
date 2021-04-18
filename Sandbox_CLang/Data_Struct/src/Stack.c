/*
    Stack.c
    The module represents my demo functions in a stack data structure.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include "Stack.h"

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
int stackTest()
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
    return 0;
}
