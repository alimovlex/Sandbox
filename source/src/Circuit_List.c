#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>

struct Node
{
	int data;
	struct Node *next;
};

void druekenList(struct Node *head)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		do
		{
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != head);
	}
	printf("\n");
}

/* Function to insert a node at the beginning of a Circular
linked list */
void push_circle(struct Node **head_ref, int data)
{
	struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
	struct Node *temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;

	/* If linked list is not NULL then set the next of last node */
	if (*head_ref != NULL)
	{
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */

	*head_ref = ptr1;
}

void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref)
{
	struct Node *slow_ptr = head;
	struct Node *fast_ptr = head;

	if (head == NULL)
		return;

	/* If there are odd nodes in the circular list then
	fast_ptr->next becomes head and for even nodes
	fast_ptr->next->next becomes head */
	while (fast_ptr->next != head && fast_ptr->next->next != head)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}

	/* If there are even elements in list then move fast_ptr */
	if (fast_ptr->next->next == head)
		fast_ptr = fast_ptr->next;

	/* Set the head pointer of first half */
	*head1_ref = head;

	/* Set the head pointer of second half */
	if (head->next != head)
		*head2_ref = slow_ptr->next;

	/* Make second half circular */
	fast_ptr->next = slow_ptr->next;

	/* Make first half circular */
	slow_ptr->next = head;
}

/* Function to exchange first and last node*/
struct Node *exchangeNodes(struct Node *head)
{
	// Find pointer to previous of last node 
	struct Node *p = head;
	while (p->next->next != head)
		p = p->next;

	/* Exchange first and last nodes using
	head and p */
	p->next->next = head->next;
	head->next = p->next;
	p->next = head;
	head = head->next;

	return head;
}

void circuitList()
{
	/* Initialize lists as empty */
	struct Node *head = NULL;
	struct Node *head1 = NULL;
	struct Node *head2 = NULL;
	/* Created linked list will be 11->2->56->12 */
	push_circle(&head, 12);
	push_circle(&head, 56);
	push_circle(&head, 2);
	push_circle(&head, 11);
	exchangeNodes(head);
	printf("Contents of Circular Linked List\n");
	druekenList(head);
	/* Split the list */
	splitList(head, &head1, &head2);
	printf("First Circular Linked List\n");
	druekenList(head1);
	printf("Second Circular Linked List\n");
	druekenList(head2);
	//deleteList(&head);
}
