/*
*
* A Minimum heap implementation in C
* Created by: Asad Zia
*
*/

#include <stdio.h>
#include <stdlib.h>

/* struct definitions */
struct node
{
	int data;
};

struct minHeap
{
	int size;
	struct node* elements;
};

/*
* the function to initialize the size of the heap 
*/
void initialize (struct minHeap* x)
{
	x->size = 0;
}

/*
* My program assumes that the heap starts from index 0 in the array
*/
void minHeapify (struct minHeap *x, int index)
{
	int smallest;
	
	if ((2*index + 1) < x->size && x->elements[2*index + 1].data < x->elements[index].data)
	{
		smallest = 2*index + 1;
	}
	else
	{
		smallest = index;
	}
	
	if ((2*index + 2) < x->size && x->elements[2*index + 2].data < x->elements[smallest].data)
	{
		smallest = 2*index + 2;
	}
	
	if (smallest != index)
	{
		
		struct node temp = x->elements[index];
		x->elements[index] = x->elements[smallest];
		x->elements[smallest] = temp;
		minHeapify(x, smallest);
		/*	
		OR:
		int temp = x->elements[index].data;
		x->elements[index].data = x->elements[smallest].data;
		x->elements[smallest].data = temp;
		minHeapify(x, smallest);
		*/
	}
}

/*
* The function to build a heap from a given array of integers 
* Note ~ The parameter size refers to the total number of elements in the array
*/
void buildHeap (struct minHeap* x, int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (x->size == 0)
		{
			x->elements = (struct node*)malloc(sizeof(struct node));
			if (x->elements == NULL) 
			{
				printf("Error in memory allocation\n");
				exit(1);
			}
		}
		else
		{
			x->elements = realloc(x->elements, sizeof(struct node) * (x->size + 1));
			if (x->elements == NULL) 
			{
				printf("Error in memory allocation\n");
				exit(1);
			}
		}
		
		struct node temp;
		temp.data = arr[i];
		x->elements[x->size] = temp;
		x->size++;
		/*
		OR:
		x->elements[x->size].data = arr[i];
		x->size++;*/
	}
	
	for (i = (x->size - 1) / 2; i >= 0; i--)
	{
		minHeapify(x, i);
	}
}

/*
* The function which inserts an element in the heap by changing the array dynamically.
*/
void insert (struct minHeap* x, int y)
{
	if (x->size == 0)
	{
		x->elements = (struct node *)malloc(sizeof(struct node));
		if (x->elements == NULL) 
		{
			printf("Error in memory allocation\n");
			exit(1);
		}
	}
	else
	{
		x->elements = realloc(x->elements, sizeof(struct node) * (x->size + 1));
		if (x->elements == NULL) 
		{
			printf("Error in memory allocation\n");
			exit(1);
		}
	}
	
	struct node temp;
	temp.data = y;
	x->size++;
	int i = x->size - 1;
	
	while (i && temp.data < x->elements[i / 2].data)
	{
		x->elements[i] = x->elements[i / 2];
		i = i / 2;
	}
	x->elements[i] = temp;
}

/*
* Deletes the minimum element in the heap
*/
void deleteNode (struct minHeap* x) 
{
	if (x->size == 0)
	{
		printf("The heap is empty!\n");
		free(x->elements);
	}
	else
	{
		printf("Element removed: %d\n", x->elements[0]);
		x->elements[0] = x->elements[x->size - 1];
		x->size--;
		x->elements = realloc(x->elements, sizeof(struct node) * x->size);
		minHeapify(x, 0);
	}
}

/*
* The function for getting the maximum element in the heap
*/
int getMax (struct minHeap *x, int i)
{
	if ((2*i + 1) >= x->size)
	{
		return x->elements[i].data;
	}
	
	int xx = getMax(x, 2*i + 1);
	int yy = getMax(x, 2*i + 2);
	
	if (xx >= yy)
	{
		return xx;
	}
	else
	{
		return yy;
	}	
}

/*
* The function for deleting the heap
*/
void deleteMinHeap (struct minHeap *x)
{
	free(x->elements);
}

void inorder_print (struct minHeap* x, int i)
{
	if (2*i + 1 <= x->size)
	{
		inorder_print(x, 2*i + 1);
	}
	
	printf("%d ", x->elements[i].data);
	
	if (2*i + 2 <= x->size)
	{
		inorder_print(x, 2*i + 2);
	}
}

/*
* The function for printing out the heap array
*/
void printing (struct minHeap* x) 
{
	int i;
	for (i = 0; i < x->size; i++)
	{
		printf("%d ", x->elements[i].data);
	}
	printf("\n");
}

/*
* the main function
*/
int main () 
{
	struct minHeap myHeap;
	int arr[10] = {6, 8, 2 ,4 , 1, 3, 9, 10, 5, 7};
	int size = 10;
	
	initialize(&myHeap);
	buildHeap(&myHeap, arr, size);
	//inorder_print(&myHeap, 0);
	//printf("\n");
	printing(&myHeap);
	printf("size: %d\n", myHeap.size);
	printf("Max: %d\n", getMax(&myHeap, 0));
	insert(&myHeap, 11);
	printing(&myHeap);
	printf("size: %d\n", myHeap.size);
	printf("Max: %d\n", getMax(&myHeap, 0));
	deleteNode(&myHeap);
	printing(&myHeap);
	deleteMinHeap(&myHeap);
	return 0;
}

/*
A dynamically allocated heap can also be used.
Simply change the initialize function to:


struct minHeap* initialize (struct minHeap* x)
{
	x = malloc(sizeof(struct minHeap));
	x->size = 0;
	return x;
}

And then change the main function to:

int main () 
{
	struct minHeap* myHeap = NULL;
	int arr[10] = {6, 8, 2 ,4 , 1, 3, 9, 10, 5, 7};
	int size = 10;
	myHeap = initialize(myHeap);
	buildHeap(myHeap, arr, size);
	printing(myHeap);
	printf("size: %d\n", myHeap->size);
	printf("Max: %d\n", getMax(myHeap, 0));
	insert(myHeap, 11);
	printing(myHeap);
	printf("size: %d\n", myHeap->size);
	printf("Max: %d\n", getMax(myHeap, 0));
	deleteNode(myHeap);
	printing(myHeap);
	deleteMinHeap(myHeap);
	return 0;
}

It is important to assign the pointer variable to the return value of the initialize function.
Otherwise the memory allocated cannot be accessed bu the myHeap pointer, resulting in a dangling pointer.
*/
