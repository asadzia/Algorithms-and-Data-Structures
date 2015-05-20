/*
*
* A program which prints the non-consecutive numbers in a linked list.
* For example for a list, 1->3->5->6->7->9 , the string 1->3->7->9 is printed. 
*
* Created by: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node* next;
};

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

void printNonConsecutive (struct node* x)
{
	struct node *current = x;
	int temp = INT_MIN, flag = 0;
	//current = current->next;

	while (current != NULL)
	{
		/* the first condition is to check for continuous consecutive numbers */
		/* the second condition is used to check for cases such as 1,3,9,10,12 where 9 and 10 will both be printed
		   even though they are consecutive. However they form the start and end of the consecutive range */
		if ((temp + 1) == current->data && current->next->data == current->data + 1)
		{
			flag = 1;
		}

		if (flag == 0)
		{
			
			temp = current->data;
			printf("%d ", temp);
		}
		current = current->next;
		flag = 0;
	}
}

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
	nodetwo->data = 3;
	nodethree->data = 4;
	nodefour->data = 5;
	nodefive->data = 7;
	nodesix->data = 9;
	nodeseven->data = 10;
	nodeeight->data = 12;
	nodenine->data = 15;

	printNonConsecutive(nodeone);
	return 0;

}
