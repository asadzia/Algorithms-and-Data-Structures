/*
*	A naive stack Simulation
*   Created by: Asad Zia
*
*/

#define MAX 20

#include <stdio.h>
#include <stdlib.h>

struct stack {
	int count;
	int container[MAX];
};

struct stack initialize(struct stack s) {
	s.count = 0;
	return s;
}

struct stack pop (struct stack s) {
	int flag = 0;
	if (s.count == 0) {
		printf("Stack Underflow!\n");
		flag = 1;
	}
	if (flag == 0) {
		printf("%d\n", s.container[s.count]);	
		s.count--;
		return s;
	}
}

struct stack push (struct stack s, int x) {
	int flag = 0;
	if (s.count == MAX) {
		printf("Stack Overflow!\n");
		flag = 1;
	}
	if (flag == 0) {
		s.count++;
		s.container[s.count] = x;
		return s;
	}
}

int isempty(struct stack s) {
	if (s.count == 0) {
		return 0;
	}else{
		return -1;
	}
}

struct stack empty (struct stack s) {
	while(isempty(s) == -1) {
		s = pop(s);
	}
	return s;
}

int main () {
	struct stack s;
	s = initialize(s);
	s = push(s,1);
	s = push(s,2);
	s = push(s,3);
	s = push(s,4);
	s = pop(s);
	s = pop(s);
	s = empty(s);
	return 0;
}
