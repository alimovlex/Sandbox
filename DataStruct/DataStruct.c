/* Written by JJL */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "DataStruct.h"

struct Node
{
	int data;
	struct Node *next;
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int position)
{
	// If linked list is empty 
	if (*head_ref == NULL)
		return;

	// Store head node 
	struct Node* temp = *head_ref;

	// If head needs to be removed 
	if (position == 0)
	{
		*head_ref = temp->next;   // Change head 
		free(temp);               // free old head 
		return;
	}

	// Find previous node of the node to be deleted 
	for (int i = 0; temp != NULL && i<position - 1; i++)
		temp = temp->next;

	// If position is more than number of ndoes 
	if (temp == NULL || temp->next == NULL)
		return;

	// Node temp->next is the node to be deleted 
	// Store pointer to the next of node to be deleted 
	struct Node *next = temp->next->next;

	// Unlink the node from linked list 
	free(temp->next);  // Free memory 

	temp->next = next;  // Unlink the deleted node from list 
}


void printList(struct Node *n)
{
	while (n != NULL)
	{
		printf("%d ", n->data);
		n = n->next;
	}
	printf("\n");
}

void list()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	// allocate 3 nodes in the heap   
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	//Manual addition to the linked list
	head->data = 3;
	head->next=second;
	second->data = 4;
	second->next=third;
	third->data = 5;
	third->next = NULL;//The end of the manual addition
	//Addition from the beginning of the list
	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);
	//End of the addition
	printf("Printing linked list:\n");
	printList(head);
	deleteNode(&head, 4);
	printf("Linked List after Deletion at position 4: ");
	printList(head);
	free(head);
}