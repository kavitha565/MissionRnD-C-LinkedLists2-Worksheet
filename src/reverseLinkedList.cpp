/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node *temp;
	int i = 0, j, Arr[10];

	for (temp = head; temp != NULL; temp = temp->next)
	{
		Arr[i] = temp->num;
		i++;

	}
	temp = head;
	for (j = i - 1; j >= 0; j--)
	{
		if (temp != NULL)
		{
			temp->num = Arr[j];
			temp = temp->next;
		}
	}
	return head;
}