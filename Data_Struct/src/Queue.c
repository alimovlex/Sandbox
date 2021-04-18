/*
    Queue.c
    The module represents my demo functions in a queue data structure.

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
#include "Queue.h"

// function to create a queue of given capacity.  
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;  // This is important, see the enqueue 
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

// Queue is full when size becomes equal to the capacity  
int isFullQueue(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0 
int isEmptyQueue(struct Queue* queue)
{
	return (queue->size == 0);
}

// Function to add an item to the queue.   
// It changes rear and size 
void addItemQueue(struct Queue* queue, int item)
{
	if (isFullQueue(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d Added to queue\n", item);
}

// Function to remove an item from queue.  
// It changes front and size 
int removeItemQueue(struct Queue* queue)
{
	if (isEmptyQueue(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Function to get front of queue 
int frontQueue(struct Queue* queue)
{
	if (isEmptyQueue(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue 
int rearQueue(struct Queue* queue)
{
	if (isEmptyQueue(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int queueTest()
{
	struct Queue* queue = createQueue(1000);

	addItemQueue(queue, 10);
	addItemQueue(queue, 20);
	addItemQueue(queue, 30);
	addItemQueue(queue, 40);

	printf("%d dequeued from queue\n\n", removeItemQueue(queue));
	printf("Front item is %d\n", frontQueue(queue));
	printf("Rear item is %d\n", rearQueue(queue));
    return 0;
}
