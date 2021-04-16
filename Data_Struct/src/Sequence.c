#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "Sequence.h"

void initSequence(struct Sequence *q)
{
	q->frnt = 1;
	q->rear = 0;
}

void insertSequence(struct Sequence *q, int x)
{
	if (q->rear < QMAX - 1) 
	{
		q->rear++;
		q->qu[q->rear] = x;
	}
	else
		printf("The Queue is full!\n");
}

int isEmptySequence(struct Sequence *q)
{
	if (q->rear < q->frnt)    
	return(1);
	else  
	return(0);
}

void printSequence(struct Sequence *q)
{
	int h;
	if (isEmptySequence(q) == 1)
	{
		printf("The Sequence is empty!\n");
		return;
	}
	for (h = q->frnt; h <= q->rear; h++)
		printf("%d ", q->qu[h]);
}

int eraseSequence(struct Sequence *q)
{
	int x;
	if (isEmptySequence(q) == 1)
	{
		printf("The Sequence is empty!\n");
		return(0);
	}
	x = q->qu[q->frnt];
	q->frnt++;
	return(x);
}

int removeSequence(struct Sequence *q)
{
	int x, h;
	if (isEmptySequence(q) == 1)
	{
		printf("The Sequence is empty!\n");
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

void sequenceTest()
{

	srand((unsigned)time(NULL));
    int size = rand()%10;
	struct Sequence *q=malloc(sizeof(struct Sequence));
	int a;
	initSequence(q);
	printSequence(q);
	for (int i = 0; i<size; i++) 
	{
		a = rand() % 10;
		insertSequence(q, a);
	}
	printf("The Sequence: ");
	printSequence(q);
		a = remove(q);
		printf("\n");
		printf("Sequence after removal:\n");
	printSequence(q);
	printf("\n");
}
