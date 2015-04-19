/*
*
* A Queue implementation in C.
*  
* Created By: Asad Zia
*/

#define MAX 20 /* maximum queue capacity */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct queue
{
	struct node* rear;
	struct node* front;
	int items;
};

struct queue* initialize (struct queue* x) 
{
	x = (struct queue*)malloc(sizeof(struct queue));
	if (x == NULL) 
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	x->rear = NULL;
	x->front = NULL;
	x->items = 0;

	return x;
}

struct queue* enqueue (struct queue *x, int y)
{
	struct node* newNode;
	int flag = 0;
	newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL) 
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}
	newNode->data = y;

	if (x->items == 0) 
	{
		x->front = newNode;
		x->rear = newNode;
		newNode->next = NULL;
		x->items++;
		printf("%d is Queued!\n", y);
		return x;
	}

	if (x->items == MAX) 
	{
		printf("The queue is full!\n");
		flag = 1;
	}

	if (flag == 0)
	{
		x->rear->next = newNode;
		newNode->next = NULL;
		x->rear = newNode;
		x->items++;
		printf("%d is Queued!\n", y);
		return x;
	} 
}

struct queue* dequeue (struct queue* x) 
{
	int flag = 0;
	struct node* myNode = x->front;
	int result;
	if (x->items == 0)
	{
		printf("The queue is empty!\n");
		flag = 1;
	}

	if (flag == 0) 
	{
		result = myNode->data;
		x->front = myNode->next;
		free(myNode);
		x->items--;

		if (x->items == 0) 
		{
			x->front = NULL;
			x->rear = NULL;
		}
		printf("%d is De-queued!\n", result);
	}
	return x;
}

void freeQueue(struct queue *x)
{
	while (x->items != 0)
	{
		x = dequeue(x);
	}
	free(x);
}

int main () 
{
	struct queue* myQueue = NULL;

	myQueue = initialize(myQueue);
	myQueue = enqueue(myQueue, 1);
	myQueue = enqueue(myQueue, 2);
	myQueue = enqueue(myQueue, 3);
	myQueue = enqueue(myQueue, 4);
	myQueue = enqueue(myQueue, 5);
	myQueue = dequeue(myQueue);
	myQueue = dequeue(myQueue);
	myQueue = dequeue(myQueue);
	myQueue = dequeue(myQueue);
	myQueue = dequeue(myQueue);
	freeQueue(myQueue);
	return 0;
}

/*
 - A statically allocated queue can also be used in this case.
   Simply change the initialize function to:

struct queue* initialize (struct queue* x) 
{
	x->rear = NULL;
	x->front = NULL;
	x->items = 0;

	return x;
}

- And change the main function as follows: 

int main () 
{
	struct queue myQueue;

	initialize(&myQueue);
	enqueue(&myQueue, 1);
	enqueue(&myQueue, 2);
	enqueue(&myQueue, 3);
	dequeue(&myQueue);
	dequeue(&myQueue);
	dequeue(&myQueue);
	return 0;
}

- Also there is no need for the freeQueue function in this case.

*/
