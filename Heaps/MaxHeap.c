/*
*
* A Maximum heap implementation in C
* Created by: Asad Zia
*
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
};

struct maxHeap 
{
	struct node* elements;
	int size;
};

/*
* 	A function for initializing the maximum heap
*/
void heapInitialize (struct maxHeap *x)
{
	x->size = 0;
}

/*
* A function for maintaining the maximum heap property
*/
void maxHeapify (struct maxHeap *x, int i)
{
	int largest;
	if ((2 * i + 1) < x->size && x->elements[2 * i + 1].data > x->elements[i].data)
	{
		largest = 2 * i + 1;
	}
	else
	{
		largest = i;
	}

	if ((2 * i + 2) < x->size && x->elements[2 * i + 2].data > x->elements[largest].data)
	{
		largest = 2 * i + 2;
	}

	if (largest != i)
	{
		struct node temp;
		temp = x->elements[i];
		x->elements[i] = x->elements[largest];
		x->elements[largest] = temp;
		maxHeapify(x, largest);
	}
}

/*
*	A function for building the maximum heap.
*/
void buildHeap (int arr[], int size, struct maxHeap* x)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (x->size == 0) 
		{
			x->elements = (struct node*)malloc(sizeof(struct node));
			if (x->elements == NULL)
			{
				printf("Error in memory allocationn");
			}
		}
		else
		{
			x->elements = realloc(x->elements, sizeof(struct node) * (x->size + 1));
			if (x->elements == NULL)
			{
				printf("Error in memory allocationn");
			}
		}

		struct node temp;
		temp.data = arr[i];
		x->elements[i] = temp;
		++x->size;
	}

	for (i = (x->size - 1) / 2; i >= 0; i--)
	{
		maxHeapify(x, i);
	}
}

/*
*	The functiion to insert an element into the heap
*/
void insert (struct maxHeap *x, int value)
{
	if (x->size == 0)
	{
		x->elements = (struct node*)malloc(sizeof(struct node));
		if (x->elements == NULL)
		{
			printf("Error in memory allocation!\n");
		}
	}
	else
	{
		x->elements = realloc(x->elements, sizeof(struct node) * (x->size + 1));
		if (x->elements == NULL)
		{
			printf("Error in memory allocation!\n");
		}
	}

	struct node temp;
	temp.data = value;
	x->size++;
	int i = x->size - 1;

	while (i && temp.data > x->elements[i / 2].data)
	{
		x->elements[i] = x->elements[i / 2];
		i = i / 2;
	}
	x->elements[i] = temp;
}

/*
*	A function to delete the root node from the heap
*/
void deleteNode (struct maxHeap *x) 
{
	if (x->size == 0)
	{
		printf("Heap is empty!\n");
		free(x->elements);
	}
	else
	{
		printf("Node deleted: %d\n", x->elements[0]);
		x->elements[0] = x->elements[x->size - 1];
		x->size--;
		x->elements = realloc(x->elements, sizeof(struct node) * x->size);
		maxHeapify(x, 0);
	}
}

/*
* A function to get the minimum element from the heap
*/
int getMin (struct maxHeap *x, int i)
{
	if ((2 * i + 1) > x->size)
	{
		return x->elements[i].data;
	}

	int l = getMin(x, 2 * i + 1);
	int r = getMin(x, 2 * i + 2);

	if (r <= l)
	{
		return r;
	}
	else
	{
		return l;
	}
}

/*
* Printing the heap out
*/
void printing (struct maxHeap* x)
{
	int i;
	for (i = 0; i < x->size; i++)
	{
		printf("%d ", x->elements[i]);
	} 
	printf("\n");
}

/*
*	Deleting the heap
*/
void freeHeap(struct maxHeap *x)
{
	free(x->elements);
}

/*
*	The main function
*/
int main ()
{
	struct maxHeap myHeap;
	int arr[] = {6, 2, 9, 1, 4, 8, 7, 3, 23, 45, 12, 65, 15};
	int size = 13, minimum;

	heapInitialize(&myHeap);
	buildHeap(arr, size, &myHeap);
	printing(&myHeap);
	insert(&myHeap, 99);
	printing(&myHeap);
	deleteNode(&myHeap);
	printing(&myHeap);

	minimum = getMin(&myHeap, 0);
	printf("Minimum node in the heap is %d\n", minimum);

	freeHeap(&myHeap);
	return 0;
}
