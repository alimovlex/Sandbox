#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include "Stack.h"

// A structure to represent a stack 
/*Переменная ошибок*/
int errorStackArray;
/*Инициализация стека*/
void initStackArray(StackArray *S) 
{
	S->uk = 0;
	errorStackArray = okStackArray;
}
/*Включение в стек*/
void putStackArray(StackArray *S, int E) 
{
	/*Если стек переполнен*/
	if (isFullStackArray(S)) 
	{
		return;
	}
	/*Иначе*/
	S->buf[S->uk] = E;				// Включение элемента
	S->uk++;							 	// Сдвиг указателя
}
/*Исключение из стека*/
void getStackArray(StackArray *S, int *E) 
{
	/*Если стек пуст*/
	if (isEmptyStackArray(S)) 
	{
		return;
	}
	/*Иначе*/
	*E = S->buf[S->uk - 1];		// Считывание элемента в переменную
	S->uk--;							 	// Сдвиг указателя
}
/*Предикат: полон ли стек*/
int isFullStackArray(StackArray *S) 
{
	if (S->uk == SIZE_STACK_ARRAY) 
	{
		errorStackArray = fullStackArray;
		return 1;
	}
	return 0;
}
/*Предикат: пуст ли стек*/
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
	/*Тестирование стека*/
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