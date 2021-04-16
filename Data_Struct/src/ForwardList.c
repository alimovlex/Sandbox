/*
    ForwardList.c
    The module represents my demo functions in a single linked list data structure.

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
#include "sglib.h"
#include "List.h"
#define NODE_COMPARATOR(e1, e2) (e1->data - e2->data)
/* Function to create a new node with given data */

struct Node *newNode(int data)
{
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Function to swap nodes x and y in linked list by
changing links */
void swapNodesForwardList(struct Node **head_ref, int x, int y)
{
	// Nothing to do if x and y are same 
	if (x == y) return;

	// Search for x (keep track of prevX and CurrX 
	struct Node *prevX = NULL, *currX = *head_ref;
	while (currX && currX->data != x)
	{
		prevX = currX;
		currX = currX->next;
	}

	// Search for y (keep track of prevY and CurrY 
	struct Node *prevY = NULL, *currY = *head_ref;
	while (currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}

	// If either x or y is not present, nothing to do 
	if (currX == NULL || currY == NULL)
		return;

	// If x is not head of linked list 
	if (prevX != NULL)
		prevX->next = currY;
	else // Else make y as new head 
		*head_ref = currY;

	// If y is not head of linked list 
	if (prevY != NULL)
		prevY->next = currX;
	else  // Else make x as new head 
		*head_ref = currX;

	// Swap next pointers 
	struct Node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

void rotateForwardList(struct Node **head_ref, int k)
{
	if (k == 0)
		return;

	// Let us understand the below code for example k = 4 and 
	// list = 10->20->30->40->50->60. 
	struct Node* current = *head_ref;

	// current will either point to kth or NULL after this loop. 
	//  current will point to node 40 in the above example 
	int count = 1;
	while (count < k && current != NULL)
	{
		current = current->next;
		count++;
	}

	// If current is NULL, k is greater than or equal to count 
	// of nodes in linked list. Don't change the list in this case 
	if (current == NULL)
		return;

	// current points to kth node. Store it in a variable. 
	// kthNode points to node 40 in the above example 
	struct Node *kthNode = current;

	// current will point to last node after this loop 
	// current will point to node 60 in the above example 
	while (current->next != NULL)
		current = current->next;

	// Change next of last node to previous head 
	// Next of 60 is now changed to node 10 
	current->next = *head_ref;

	// Change head to (k+1)th node 
	// head is now changed to node 50 
	*head_ref = kthNode->next;

	// change next of kth node to NULL 
	// next of 40 is now NULL 
	kthNode->next = NULL;
}

/* Function to reverse the linked list */
void reverseForwardList(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next = NULL;
	while (current != NULL)
	{
		// Store next 
		next = current->next;

		// Reverse current node's pointer 
		current->next = prev;

		// Move pointers one position ahead. 
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void pushForwardList(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
    //SGLIB_SORTED_LIST_ADD(struct Node, head_ref, new_node, NODE_COMPARATOR, next); bugging sorting on addition
}

/* Given a reference (pointer to pointer) to the head of a list
and a position, deletes the node at the given position */
void deleteNodeForwardList(struct Node **head_ref, int position)
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


void printForwardList(struct Node *n)
{
	while (n != NULL)
	{
		printf("%d ", n->data);
		n = n->next;
	}
	printf("\n");
}

void deleteForwardList(struct Node** head_ref)
{
	/* deref head_ref to get the real head */
	struct Node* current = *head_ref;
	struct Node* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	/* deref head_ref to affect the real head back
	in the caller. */
	*head_ref = NULL;
}

/* Counts no. of nodes in linked list */
int nodesCountForwardList(struct Node* head)
{
	int count = 0;  // Initialize count 
	struct Node* current = head;  // Initialize current 
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

/* Adds contents of two linked lists and return the head node of resultant list */
struct Node* addTwoForwardLists(struct Node* first, struct Node* second)
{
	struct Node* res = NULL; // res is head node of the resultant list 
	struct Node *temp, *prev = NULL;
	int carry = 0, sum;

	while (first != NULL || second != NULL) //while both lists exist 
	{
		// Calculate value of next digit in resultant list. 
		// The next digit is sum of following things 
		// (i)  Carry 
		// (ii) Next digit of first list (if there is a next digit) 
		// (ii) Next digit of second list (if there is a next digit) 
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

		// update carry for next calulation 
		carry = (sum >= 10) ? 1 : 0;

		// update sum if it is greater than 10 
		sum = sum % 10;

		// Create a new node with sum as data 
		temp = newNode(sum);

		// if this is the first node then set it as head of the resultant list 
		if (res == NULL)
			res = temp;
		else // If this is not the first node then connect it to the rest. 
			prev->next = temp;

		// Set prev for next insertion 
		prev = temp;

		// Move first and second pointers to next nodes 
		if (first) first = first->next;
		if (second) second = second->next;
	}

	if (carry > 0)
		temp->next = newNode(carry);

	// return head of the resultant list 
	return res;
}


void forwardListTest()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* first = NULL;

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
	pushForwardList(&head, 7);
	pushForwardList(&head, 1);
	pushForwardList(&head, 3);
	pushForwardList(&head, 2);
	//End of the addition
	//circular(head);
	printf("Printing ForwardList:\n");
	printForwardList(head);
	printf("count of nodes in ForwardList is %d\n", nodesCountForwardList(head));
	deleteNodeForwardList(&head, 4);
	printf("ForwardList after Deletion at position 4: ");
	printForwardList(head);
	printf("count of nodes in ForwardList is %d\n", nodesCountForwardList(head));
	printf("ForwardList before calling swapNodes() \n");
	printForwardList(head);
	swapNodesForwardList(&head, 2, 5);
	printf("ForwardList after calling swapNodes() \n");
	printForwardList(head);
	reverseForwardList(&head);
	printf("Reversed ForwardList \n");
	printForwardList(head);
	rotateForwardList(&head, 4);
	printf("Rotated ForwardList \n");
	printForwardList(head);

	//detectloop(head);
	// create first list 7->5->9->4->6 
	pushForwardList(&first, 6);
	pushForwardList(&first, 4);
    pushForwardList(&first, 9);
	pushForwardList(&first, 5);
	pushForwardList(&first, 7);
	printf("First ForwardList is ");
    printForwardList(first);
    printf("First Reversed ForwardList is ");
    SGLIB_LIST_REVERSE(struct Node, first, next);
	printForwardList(first);
    printf("First Sorted ForwardList is ");
    SGLIB_LIST_SORT(struct Node, first, NODE_COMPARATOR, next);
    printForwardList(first);
	printf("Wiping ForwardList\n");
	deleteForwardList(&head);
	deleteForwardList(&first);
	printf("ForwardList deleted\n");
}

