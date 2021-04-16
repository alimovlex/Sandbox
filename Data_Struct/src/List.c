#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "List.h"
/* Node of a doubly linked list */
/* Function to reverse a Doubly Linked List */

void reverseList(struct Node **head_ref)
{
	struct Node *temp = NULL;
	struct Node *current = *head_ref;

	/* swap next and prev for all nodes of
	doubly linked list */
	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	/* Before changing head, check for the cases like empty
	list and list with only one node */
	if (temp != NULL)
		*head_ref = temp->prev;
}

/* Function to delete a node in a Doubly Linked List.
head_ref --> pointer to head node pointer.
del  -->  pointer to node to be deleted. */
void eraseNodeList(struct Node** head_ref, struct Node* del)
{
	/* base case */
	if (*head_ref == NULL || del == NULL)
		return;

	/* If node to be deleted is head node */
	if (*head_ref == del)
		*head_ref = del->next;

	/* Change next only if node to be deleted is NOT the last node */
	if (del->next != NULL)
		del->next->prev = del->prev;

	/* Change prev only if node to be deleted is NOT the first node */
	if (del->prev != NULL)
		del->prev->next = del->next;

	/* Finally, free the memory occupied by del*/
	free(del);
}


/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void pushList(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	/* 2. put in the data  */
	new_node->data = new_data;
	/* 3. Make next of new node as head and previous as NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	/* 4. change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	/* 5. move the head to point to the new node */
	(*head_ref) = new_node;
}

void insertBeforeList(struct Node** head_ref, struct Node* next_node, int new_data)
{
	/*1. check if the given next_node is NULL */
	if (next_node == NULL) {
		printf("the given next node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* 3. put in the data */
	new_node->data = new_data;

	/* 4. Make prev of new node as prev of next_node */
	new_node->prev = next_node->prev;

	/* 5. Make the prev of next_node as new_node */
	next_node->prev = new_node;

	/* 6. Make next_node as next of new_node */
	new_node->next = next_node;

	/* 7. Change next of new_node's previous node */
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
	/* 8. If the prev of new_node is NULL, it will be
	the new head node */
	else
		(*head_ref) = new_node;

}

/* Given a node as prev_node, insert a new node after the given node */
void insertAfterList(struct Node* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL) 
	{
		printf("the given previous node cannot be NULL");
		return;
	}
	/* 2. allocate new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	/* 3. put in the data  */
	new_node->data = new_data;
	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;
	/* 5. Make the next of prev_node as new_node */
	prev_node->next = new_node;
	/* 6. Make prev_node as previous of new_node */
	new_node->prev = prev_node;
	/* 7. Change previous of new_node's next node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end  */
void appendList(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *head_ref; /* used in step 5*/
						   /* 2. put in the data  */
	new_node->data = new_data;
	/* 3. This new node is going to be the last node, so
	make next of it as NULL*/
	new_node->next = NULL;
	/* 4. If the Linked List is empty, then make the new
	node as head */
	if (*head_ref == NULL) 
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;
	/* 6. Change the next of last node */
	last->next = new_node;
	/* 7. Make last node as previous of new node */
	new_node->prev = last;
	return;
}
// This function prints contents of linked list starting from the given node 
void printList(struct Node* node)
{
	struct Node* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) 
	{
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}
	printf("\nTraversal in reverse direction \n");
	while (last != NULL) 
	{
		printf(" %d ", last->data);
		last = last->prev;
	}
	printf("\n");
}

void listTest()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	// Insert 7 at the beginning. So linked list becomes 7->NULL 
	pushList(&head, 7);
	// Insert 1 at the beginning. So linked list becomes 1->7->NULL 
	pushList(&head, 1);
	pushList(&head, 9);
	// Insert 4 at the end. So linked list becomes 1->7->4->NULL 
	appendList(&head, 4);
	printf("Created DLL is: ");
	printList(head);
	reverseList(&head);
	printf("Reversed Linked list \n");
    printList(head);
	/* delete nodes from the doubly linked list */
	eraseNodeList(&head, head); /*delete first node*/
	eraseNodeList(&head, head->next); /*delete middle node*/
	eraseNodeList(&head, head->next); /*delete last node*/
	/* Modified linked list will be NULL<-8->NULL */
	printf("Modified Linked list \n");
	printList(head);
}

