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
*	Heapsort function
*/
void heapSort (struct maxHeap *x, int arr[], int size)
{
	int i;
	buildHeap(arr, size, x);

	int count = x->size;	
	for (i = x->size - 1; i > 0; i--)
	{
		struct node temp;
		temp = x->elements[0];
		x->elements[0] = x->elements[i];
		x->elements[i] = temp;
		x->size--;		/* To ignore the swapped element in the last position when using maxHeapify. */
		maxHeapify(x, 0);
	}
	x->size = count;
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
	struct maxHeap myHeap2;
	int arr[] = {6, 2, 9, 1, 4, 8, 7, 3, 23, 45, 12, 65, 15};
	int size = 13, minimum;

	printf("The result of heapSort:\n");
	heapInitialize(&myHeap2);
	heapSort(&myHeap2, arr, size);
	printing(&myHeap2);

	freeHeap(&myHeap2);
	return 0;
}
