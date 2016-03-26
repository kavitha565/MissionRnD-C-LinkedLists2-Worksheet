/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>
struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	struct node *temp;
	int i = 0, mid, len;
	for (temp = head; temp != NULL; temp = temp->next)
	{
		i++;
	}
	len = i;
	mid = len / 2;
	if (len % 2 == 0)
	{
		i = 1;
		for (temp = head; temp != NULL; temp = temp->next)
		{

			if (i == mid)
			{
				return ((temp->num) + (temp->next->num)) / 2;
			}
			else
				i++;
		}
	}
	else{
		i = 1;
		for (temp = head; temp != NULL;)
		{
			if (i == mid + 1)
			{
				return (temp->num);
			}
			else
				i++;
			temp = temp->next;
		}
	}
}
