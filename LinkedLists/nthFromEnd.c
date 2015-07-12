/*
* A program to return the nth node from the end of a list
*
* Created by Asad zia.
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

void freeList (struct node* x)
{
	while (x != NULL)
	{
		struct node* temp = x->next;
		free(x);
		x = temp;
	}
}

int nthFromEnd (struct node* x, int n)
{
	int count = 0;
	struct node* current = x, *current2 = x;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	printf("%d", count);
	int length = count - n;

	while (length != 0)
	{
		current2 = current2->next;
		length--;
	}

	return current2->data;
}

int main () 
{
	struct node* one;
	one = (struct node*)malloc(sizeof(struct node));
	if (one == NULL)
	{
		printf("Error in memory allocation!");
		exit(1);
	}
	one->data = 1;

	struct node* two;
	two = (struct node*)malloc(sizeof(struct node));
	if (two == NULL)
	{
		printf("Error in memory allocation!");
		exit(1);
	}
	two->data = 2;
	one->next = two;

	struct node* three;
	three = (struct node*)malloc(sizeof(struct node));
	if (three == NULL)
	{
		printf("Error in memory allocation!");
		exit(1);
	}
	three->data = 3;
	two->next = three;

	struct node* four;
	four = (struct node*)malloc(sizeof(struct node));
	if (four == NULL)
	{
		printf("Error in memory allocation!");
		exit(1);
	}
	four->data = 4;
	three->next = four;

	struct node* five;
	five = (struct node*)malloc(sizeof(struct node));
	if (five == NULL)
	{
		printf("Error in memory allocation!");
		exit(1);
	}
	five->data = 5;
	four->next = five;

	struct node* six;
	six = (struct node*)malloc(sizeof(struct node));
	if (six == NULL)
	{
		printf("Error in memory allocation!");
		exit(1);
	}
	six->data = 1;
	five->next = six;

	struct node* seven;
	seven = (struct node*)malloc(sizeof(struct node));
	if (seven == NULL)
	{
		printf("Error in memory allocation!");
		exit(1);
	}
	seven->data = 1;
	six->next = seven;
	seven->next = NULL;

	int n = 4;
	int result = nthFromEnd(one, n);
	printf("Nth node from end: %d\n", result);
	freeList(one);
	return 0;
}

/*
Alternative approach using two pointers:

void nthfromEnd (struct node* list, int n)
{
	struct node* main_ptr = list;
	struct node* ref_ptr = list;

	int count = 0;

	while (count < n)
	{
		ref_ptr = ref_ptr->next;
		count++;
	}

	while (ref_ptr->next != NULL)
	{
		main_ptr = main_ptr->next;
		ref_ptr = ref_ptr->next;
	}

	cout << "The nth node from the end is " <<  main_ptr->data << endl;
}
*/
