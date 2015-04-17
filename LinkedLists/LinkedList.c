/*
*
* A linked list implemetation.
*	
* Created By: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

struct list {
	char data;
	struct list *next;
};

struct list* append (struct list* x, char c) {
	struct list *newNode;
	newNode = (struct list*)malloc(sizeof(struct list));
	if (newNode == NULL) 
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}
	newNode->data = c;
	newNode->next = NULL;

	if (x == NULL) 
	{
		return newNode;
	}
	
	struct list* cur = x;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = newNode;
	return x;	
}

struct list* prepend (struct list *x, char c) {
	struct list *newNode, *cur;
	newNode = (struct list*)malloc(sizeof(struct list));
	if (newNode == NULL) 
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}
	newNode->data = c;
	if (x == NULL) 
	{
		newNode->next = NULL;
		return newNode;
	}
	newNode->next = x;
	return newNode;
}

struct list* insert(struct list *x, char c, int q) {
	struct list *newNode, *cur = x, *cur2 = x;
	int count = 0, i = 0;
	newNode = (struct list*)malloc(sizeof(struct list));

	if (newNode == NULL) 
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}
	newNode->data = c;

	while (cur != NULL) {
		count++;
		cur = cur->next;
	}

	if (q < 0 || q > count) {
		printf("Invalid Value of the insert position!\n");
		exit(1);
	}

	if (q == 0 || x == NULL) {
		return prepend(x, c);
	}

	if (q == count) {
		return append(x, c);
	}

	for (i = 0; i < (q - 1); i++) {
		cur2 = cur2->next;
	}

	newNode->next = cur2->next;
	cur2->next = newNode;
	return x;
}

struct list* reverse (struct list *x) {
	struct list *current = x, *temp, *result = NULL;
	while (current != NULL) {
		temp = current->next;
		current->next = result;
		result = current;
		current = temp;
	}
	return result;
}

void printing (struct list *x) {
	struct list* current = x;
	while (current != NULL) {
		printf("%c ", current->data);
		current = current->next;
	}
	printf("\n");
}

void empty (struct list *x) {
	struct list *temp;
	while (x != NULL) {
		temp = x->next;
		free(x);
		x = temp;
	}
	printf("List is emptied!\n");
}


int main () {
	struct list* myList;
	myList = append(myList, 'a');
	myList = prepend(myList, 'p');
	myList = prepend(myList, 'w');
	myList = prepend(myList, 't');
	myList = insert(myList, 'q', 0);
	myList = insert(myList, 'r', 4);
	printing(myList);
	myList = reverse(myList);
	printing(myList);
	empty(myList);
	return 0;
}

