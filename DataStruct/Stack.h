#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif
#ifndef _STACK_ARRAY_H_
#define _STACK_ARRAY_H_
/*Размер стека*/
#define SIZE_STACK_ARRAY 100
typedef struct
{
	int buf[SIZE_STACK_ARRAY];						// Буфер стека
	unsigned uk;													// Указатель
} StackArray;
/*Описание исключительных ситуаций*/
const int okStackArray = 0;// Все нормально
const int fullStackArray = 1;// Стек переполнен
const int emptyStackArray = 2;// Стек пуст
/*********************************/
/*Переменная ошибок*/
extern int errorStackArray;
/*Базовый тип стека*/
DLL void stack();
/******************/
/*Функции работы со стеком*/
DLL void initStackArray(StackArray *S);									// Инициализация стека
DLL void putStackArray(StackArray *S, int E);			// Включение в стек
DLL void getStackArray(StackArray *S, int *E);			// Исключение из стека
DLL int isFullStackArray(StackArray *S);								// Предикат: полон ли стек
DLL int isEmptyStackArray(StackArray *S);								// Предикат: пуст ли стек
/**************************/
#endif