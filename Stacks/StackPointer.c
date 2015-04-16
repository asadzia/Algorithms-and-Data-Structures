/*
*	A stack Simulation using pointers
*   Created by: Asad Zia
*
*/

#define MAX 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
	unsigned int count;
	char **container;
};

void initialize (struct stack* s) {
	int i;
	s->container = (char**)malloc(sizeof(char*) * MAX);
	if (s == NULL) {
		printf("Error in memory allocation!\n");
		exit(1);
	}
	for (i = 0; i < MAX; i++) {
		s->container[i] = (char*)malloc(sizeof(char) * MAX);
		if (s->container[i] == NULL) {
			printf("Error in memory Allocation!\n");
			exit(1);
		}
	}
	s->count = 0;
}


void push (struct stack* s, char* str) {
	int flag = 0;
	if (s == NULL) {
		printf("Stack does not exist!\n");
	}
	if (s->count == MAX) {
		printf("Stack Overflow!\n");
		flag = 1;
	}
	if (flag == 0) {
		s->count++;
		strcpy(s->container[s->count], str);
	}
}

void pop (struct stack* s) {
	int flag = 0;
	if (s == NULL) {
		printf("Stack does not exist!\n");
		exit(1);
	}
	if (s->count == 0) {
		printf("Stack Underflow!\n");
		flag = 1;
	}
	if (flag == 0) {
		printf("%s\n", s->container[s->count]);
		s->count--;
	}
}

int isempty(struct stack *s) {
	if (s->count == 0) {
		return 0;
	}
	else
	{
		return -1;
	} 
}

void empty (struct stack *s) {
	while (isempty(s) == -1) {
		pop(s);
	}
}

void deleteStack (struct stack *s) {
	int i;
	for (i = 0; i < MAX; i++) {
		free(s->container[i]);
	}
	free(s->container);
}

int main () {
	struct stack s;
	initialize(&s);
	push(&s, "How");
	push(&s, "art");
	push(&s, "thou");
	push(&s, "?");
	empty(&s);
	deleteStack(&s);
	return 0;
}
