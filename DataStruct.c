/* Written by JJL */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
typedef struct Node 
{
	void *data;
	struct Node *next;
} Node;

Node *add(Node *head, void *data, int bytes) 
{
	Node *tmp = malloc(sizeof(Node));
	memcpy(tmp->data = malloc(bytes), (char*)data, bytes);
	tmp->next = head;
	return tmp;
}

void *get(Node *head, int index) 
{
	for (; index--; head = head->next);
	return head->data;
}

int size(Node *head) 
{
	int size = 0;
	for (; head; head = head->next, size++);
	return size;
}

void freeList(Node *head) 
{
		while (head) 
		{
			Node *p = head;
			head = head->next;
			free(p->data);
			free(p);
			}
}


void list() 
{
	char a = 'a';
	int b = 20003;
	short c = 8343;

	Node *head = NULL;
	head = add(head, &a, 1);
	head = add(head, &b, 4);
	head = add(head, &c, 2);

	printf("list size: %d\n", size(head));
	printf("values: %c, %d, %hd\n", *(char*)get(head, 2),
		*(int*)get(head, 1),
		*(short*)get(head, 0));
	freeList(head);
}
