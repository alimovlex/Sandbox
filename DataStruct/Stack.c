#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include "Stack.h"


struct comp //Структура с названием comp(от слова component)
{
	int Data; //Какие-то данные(могут быть любыми, к примеру можно написать int key; char Data; так-же можно добавить еще какие-либо данные)
	struct comp *next;//Указатель типа comp на следующий элемент
};

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

//---------------------------------------------------habr stack

void s_push(struct comp **top, int D) //функция типа void(ничего не возвращает) которая принимает указатль на вершину стека и переменную которая будет записываться в ячейку
{
	struct comp *q = (struct comp*)malloc(sizeof(struct comp)); //Создаем новый указатель q типа структуры comp и выделяем память для нового элемента
	q->Data = D; //Записываем необходимое число  в Data элемента
	if (top == NULL) //Если вершины нет, то есть стек пустой
	{
		*top = q; //вершиной стека будет новый элемент
	}
	else //если стек не пустой
	{
		q->next = *top; //Проводим связь от нового элемента, к вершине. Тоесть кладем книжку на вершину стопки.
		*top = q; //Обозначаем, что вершиной теперь является новый элемент
	}
}

void s_delete_key(struct comp **top, int N) //функция которая принимает вершину top и число которое нужно удалить
{
	struct comp *q = *top; //создаем указатель типа comp и приравниваем(ставим) его на вершину стека
	struct comp *prev = NULL;//создаем указатель на предыдуший элемент, с начала он будет пустым
	while (q != NULL) //пока указатель q не пустой, мы будем выполнять код в цикле, если он все же пустой цикл заканчивается
	{
		if (q->Data == N)
		{//если Data элемента равна числу, которое нам нужно удалить
			if (q == *top) //если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
			{
				*top = q->next;//передвигаем вершину на следующий элемент
				free(q);//очищаем ячейку
				q->Data = NULL; //Далее во избежание ошибок мы обнуляем переменные в удаленной ячейке, так как в некоторых компиляторах удаленная ячейка имеет переменные не NULL значения, а дословно "Чтение памяти невозможно" или числа  "-2738568384" или другие, в зависимости от компилятора.
				q->next = NULL;
			}
			else//если элемент последний или находится между двумя другими элементами
			{
				prev->next = q->next;//Проводим связь от предыдущего элемента к следующему
				free(q);//очищаем ячейку 
				q->Data = NULL;//обнуляем переменные
				q->next = NULL;
			}
		}// если Data элемента НЕ равна числу, которое нам нужно удалить
		prev = q; //запоминаем текущую ячейку как предыдущую
		q = q->next;//перемещаем указатель q на следующий элемент
	}
}

void s_print(struct comp *top) //принимает указатель на вершину стека	
{ 	
	struct comp *q = top; //устанавливаем q на вершину
	while (q) //пока q не пустой (while(q) эквивалентно while(q != NULL))
	{ 
		printf_s("%i", q->Data);//выводим на экран данные ячейки стека
		q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
	}
	printf("\n");
}

void habrostack()
{
	printf("Habrostack initial value\n");
	struct comp *top = NULL; //в начале программы у нас нет очереди, соответственно вершины нет, даем ей значение NULL
					  //Дальше начинаем добавлять цифры от 1 до 5 в наш стек
	s_push(&top, 1);
	s_push(&top, 2);
	s_push(&top, 3);
	s_push(&top, 4);
	s_push(&top, 5);
	//после выполнения функций в стеке у нас будет 54321
	s_print(top);//выводим
	s_delete_key(&top, 4); //Затем удаляем 4, в стеке получается 5321
	printf("After deletion\n");
	s_print(top);//выводим
}