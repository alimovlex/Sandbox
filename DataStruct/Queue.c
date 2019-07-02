#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "Queue.h"

#define QMAX 100
struct queue
{
	int qu[QMAX];
	int rear, frnt;
};

void init(struct queue *q) 
{
	q->frnt = 1;
	q->rear = 0;
	return;
}

void insert(struct queue *q, int x) 
{
	if (q->rear < QMAX - 1) 
	{
		q->rear++;
		q->qu[q->rear] = x;
	}
	else
		printf("The Queue is full!\n");
	return;
}

int isempty(struct queue *q) 
{
	if (q->rear < q->frnt)    
	return(1);
	else  
	return(0);
}

void print(struct queue *q) 
{
	int h;
	if (isempty(q) == 1) 
	{
		printf("The queue is empty!\n");
		return;
	}
	for (h = q->frnt; h <= q->rear; h++)
		printf("%d ", q->qu[h]);
	return;
}

int remove(struct queue *q) 
{
	int x;
	if (isempty(q) == 1) 
	{
		printf("The queue is empty!\n");
		return(0);
	}
	x = q->qu[q->frnt];
	q->frnt++;
	return(x);
}

int removex(struct queue *q) 
{
	int x, h;
	if (isempty(q) == 1) 
	{
		printf("The queue is empty!\n");
		return(0);
	}
	x = q->qu[q->frnt];
	for (h = q->frnt; h < q->rear; h++) 
	{
		q->qu[h] = q->qu[h + 1];
	}
	q->rear--;
	return(x);
}

void queue(int size)
{
	srand((unsigned)time(NULL));
	struct queue *q=malloc(sizeof(struct queue));
	int a;
	init(q);
	print(q);
	for (int i = 0; i<size; i++) 
	{
		a = rand() % 10;
		insert(q, a);
	}
	printf("The queue : ");
	print(q);
		a = remove(q);
		printf("\n");
	print(q);
	printf("\n");
}