/*
*
* A program to implement a doubly linked list
* 
* Created By: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

struct list 
{
	char data;
	struct list *next;
	struct list *prev;
};

struct list* append (struct list* x, char c) 
{
	struct list *newNode;
	newNode = (struct list* )malloc(sizeof(struct list));
	if (newNode == NULL) {
		printf("Error in memory allocation!\n");
	}
	newNode->data = c;

	if (x == NULL) {
		newNode->next = NULL;
		newNode->prev = NULL;
		x = newNode;
		return x;
	}

	struct list *current = x;
	while (current->next != NULL) 
	{
		current = current->next;
	}
	current->next = newNode;
	newNode->prev = current;
	newNode->next = NULL;
	return x;
}

struct list* prepend (struct list* x, char c) 
{
	struct list *newNode;
	newNode = (struct list* )malloc(sizeof(struct list));
	if (newNode == NULL) {
		printf("Error in memory allocation!\n");
	}
	newNode->data = c;

	if (x == NULL) {
		newNode->next = NULL;
		newNode->prev = NULL;
		x = newNode;
		return x;
	}
	newNode->next= x;
	x->prev = newNode;
	newNode->prev = NULL;
	return newNode;
}

struct list* reverse (struct list* x) 
{
	struct list* current = x;
	struct list* temp;
	struct list* result = NULL;
	while (current != NULL)
	{
		temp = current->next;
		current->next = result;
		current->prev = temp;
		result = current;
		current = temp;
	}
	return result;
}

struct list* removeElement (struct list* x, char c) 
{
	struct list *current = x;
	struct list* temp, *temp2;
	while (current != NULL && current->data != c) 
	{
		current = current->next;
	}

	/* first element */
	if (current->prev == NULL) 
	{
		temp = current->next;
		free(current);
		temp->prev = NULL;
		x = temp;
		return x;
	}

	if (current->next == NULL) 
	{
		temp = current->prev;
		free(current);
		temp->next = NULL;
		return x;
	}

	temp = current->next;
	temp2 = current->prev;
	temp->prev = temp2;
	temp2->next = temp;
	free(current);
	return x;
}

void printList (struct list *x) 
{
	struct list* current = x;
	while (current != NULL) 
	{
		printf("%c ", current->data);
		current = current->next;
	}	
	printf("\n");
}

void emptyList (struct list* x) 
{
	struct list* temp;
	while (x != NULL) {
		temp = x->next;
		free(x);
		x = temp;
	}
}

int main () 
{
	struct list *myList = NULL;
	char option, c;

	while (1) 
	{
		scanf("%c", &option);
		getchar();
		switch(option)
		{
			case 'a':
				scanf("%c", &c);
				getchar();
				myList = append(myList, c);
				break;

			case 'b':
				scanf("%c", &c);
				getchar();
				myList = prepend(myList, c);
				break;

			case 'c':
				myList = reverse(myList);
				break;

			case 'd':
				scanf("%c", &c);
				getchar();
				myList = removeElement(myList, c);
				break;

			case 'e':
				printList(myList);
				break;

			case 'f':
				emptyList(myList);
				exit(1);
				break;
		}
	}
	return 0;
}
