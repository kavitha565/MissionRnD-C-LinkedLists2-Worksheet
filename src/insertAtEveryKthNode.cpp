/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node *create_node(int data)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->num = data;
	newnode->next = NULL;
	return newnode;
}
struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 0)
		return NULL;
	int count = 0, i;
	struct node *newnode=NULL;
	struct node *curr, *temp, *temp1;
	curr = head;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		count = count + 1;
	}
	if (K > count)
		return head;
	else
	{
		temp = head;
		temp1 = temp;
		for (i = 1; i <= count; i++)
		{
			temp1 = temp;
			temp = temp->next;
			if (i % K == 0)
			{
				newnode = create_node(K);
				temp1->next = newnode;
				newnode->next = temp;
			}
		}
	}
	return(head);
}
