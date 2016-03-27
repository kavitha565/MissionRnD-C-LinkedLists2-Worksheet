/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>
struct node
{
	int num;
	struct node *next;
}*head, *current;
struct node *createnode(int data)
{
	//static struct node *head = NULL;
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->num = data;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
		current = new_node;
	}
	else
	{
		current->next = new_node;
		current = new_node;
	}
	return head;
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL || head2 == NULL)
		return NULL;
	int temp[10], i, k = 0;
	struct node *result;
	struct node *temp1 = head1, *temp2 = head2;
	while (temp1 != NULL&&temp2 != NULL)
	{
		if ((temp1->num)< (temp2->num))
		{
			temp[k++] = temp1->num;
			temp1 = temp1->next;
		}
		else
		{
			temp[k++] = temp2->num;
			temp2 = temp2->next;
		}
	}
	while (temp1 != NULL)
	{
		temp[k++] = temp1->num;
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		temp[k++] = temp2->num;
		temp2 = temp2->next;
	}
	for (i = 0; i < k; i++)
		result = createnode(temp[i]);
	return result;
}