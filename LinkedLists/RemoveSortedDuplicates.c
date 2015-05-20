/*
*
* A program to remove duplicates from a sorted linked list in C.
*
* Created By: Asad zia
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
* A function to remove duplicates
*/ 
struct node* RemoveDuplicates (struct node* x)
{
	struct node* cur = x;
	struct node* temp;

	while (cur->next != NULL)
	{
		if (cur->data == cur->next->data)
		{
			temp = cur->next->next;
			free(cur->next);
			cur->next = temp;
		}
		else
		{
			cur = cur->next;
		}
	}
	return x;
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
	nodenine->next = NULL;

	nodeone->data = 1;
	nodetwo->data = 2;
	nodethree->data = 2;
	nodefour->data = 3;
	nodefive->data = 4;
	nodesix->data = 4;
	nodeseven->data = 6;
	nodeeight->data = 6;
	nodenine->data = 15;

	nodeone = RemoveDuplicates(nodeone);
	printList(nodeone);
	freeList(nodeone);
	return 0;

}

/*
To remove duplicates from an unsorted List, Hashing can be used.
*/
