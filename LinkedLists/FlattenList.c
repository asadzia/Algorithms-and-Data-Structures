/*
*
* A program to flatten a linked list in C.
*
* Created by: Asad Zia
*/

#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *next;
	struct node *child;
};

struct node* newNode (int x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Error in memroy allocation\n");
		exit(1);
	}

	temp->next = temp->child = NULL;
	temp->data = x;
	return temp;
}

struct node* flattenList (struct node* x)
{
	struct node* current = x, *tail = x, *temp;

	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	while (current != NULL)
	{
		if (current->child != NULL)
		{
			tail->next = current->child;

			while (tail->next != NULL)
			{
				tail = tail->next;
			}
		}

		current = current->next;
	}

	return x;
}

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

int main ()
{
	/*
	Making the following list:
	1->2->3->4->5
	|        |
	6->7	 8->9
				|
				10
	*/

	struct node *myList_one = newNode(1);
	struct node *myList_two = newNode(2);
	struct node *myList_three = newNode(3);
	struct node *myList_four = newNode(4);
	struct node *myList_five = newNode(5);
	struct node *myList_six = newNode(6);
	struct node *myList_seven = newNode(7);
	struct node *myList_eight = newNode(8);
	struct node *myList_nine = newNode(9);
	struct node *myList_ten = newNode(10);

	myList_one->next = myList_two;
	myList_two->next = myList_three;
	myList_three->next = myList_four;
	myList_four->next = myList_five;
	myList_one->child = myList_six;
	myList_six->next = myList_seven;
	myList_four->child = myList_eight;
	myList_eight->next = myList_nine;
	myList_nine->child = myList_ten;

	myList_one = flattenList(myList_one);
	printList(myList_one);
	return 0;
}
