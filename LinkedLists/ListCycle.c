/*
*
* A program to find a cycle in a linked list.
*
*
* Created by: Asad zia
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

/*
* A function to create a new node
*/ 
struct node* newNode (struct node* x)
{
	x = (struct node*)malloc(sizeof(struct node));
	if (x == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	x->next = NULL;
	return x;
}

/*
* A function to remove the loop/cycle in a linked list
*/
void RemoveLoop (struct node* x, struct node* y)
{
	int count = 1;
	struct node* cur1 = x, *cur2 = x;

	while (cur1->next != cur2)
	{
		count++;
		cur1 = cur1->next;
	}

	cur1 = cur2 = y;

	while (count != 0)
	{
		cur2 = cur2->next;
		count--;
	}

	/* move pointers so they meet at the loop starting node */
	while (cur2 != cur1)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	/* move the second pointer to the "apparent" last node in the list */
	while (cur2->next != cur1)
	{
		cur2 = cur2->next;
	}

	cur2->next = NULL;
}

/*
* A function to detect and remove the cycle in a linked list
*/
int DetectLoop (struct node* x)
{
	/* use floyds loop detection algorithm */
	struct node* slow = x, *fast = x;

	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			RemoveLoop(slow, x);
			return 1;
		}
	}
	return 0; /* return 0 if there is no loop */
}

/*
* A function for printing the list
*/
void printList (struct node* x)
{
	struct node* cur = x;

	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/*
* A functtion to free the list
*/
void freeList (struct node* x)
{
	struct node* cur = x, *temp;

	while (cur != NULL)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
}

/*
* The main function
*/
int main ()
{
	struct node* nodeone;
	struct node* nodetwo;
	struct node* nodethree;
	struct node* nodefour;
	struct node* nodefive;
	struct node* nodesix;
	struct node* nodeseven;
	struct node* nodeeight;
	struct node* nodenine;

	nodeone = newNode(nodeone);
	nodetwo = newNode(nodetwo);
	nodethree = newNode(nodethree);
	nodefour = newNode(nodefour);
	nodefive = newNode(nodefive);
	nodesix = newNode(nodesix);
	nodeseven = newNode(nodeseven);
	nodeeight = newNode(nodeeight);
	nodenine = newNode(nodenine);

	nodeone->next = nodetwo;
	nodetwo->next = nodethree;
	nodethree->next = nodefour;
	nodefour->next = nodefive;
	nodefive->next = nodesix;
	nodesix->next = nodeseven;
	nodeseven->next = nodeeight;
	nodeeight->next = nodenine;
	nodenine->next = nodethree;

	nodeone->data = 1;
	nodetwo->data = 3;
	nodethree->data = 4;
	nodefour->data = 5;
	nodefive->data = 7;
	nodesix->data = 9;
	nodeseven->data = 10;
	nodeeight->data = 12;
	nodenine->data = 15;

	int result = DetectLoop(nodeone);

	if (result == 1)
	{
		printf("A loop was detected!\n");
	}
	else
	{
		printf("No loop was detected!\n");
	}

	printList(nodeone);
	freeList(nodeone);
	return 0;

}
