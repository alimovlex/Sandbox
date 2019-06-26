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
struct StackNode 
{
	int data;
	struct StackNode* next;
};

struct StackNode* neueNode(int data)
{
	struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(struct StackNode* root)
{
	return !root;
}

void pusch(struct StackNode** root, int data)
{
	struct StackNode* stackNode = neueNode(data);
	stackNode->next = *root;
	*root = stackNode;
	printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(struct StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

void stack()
{
	struct StackNode* root = NULL;
	pusch(&root, 10);
	pusch(&root, 20);
	pusch(&root, 30);
	printf("%d popped from stack\n", pop(&root));
	printf("Top element is %d\n", peek(root));
}