#include <iostream>
#include <vector>

using namespace std;

struct node
{
	vector<int> h_arr;
};

bool hasleftChild (struct node& heap, int i)
{
	if (heap.h_arr.size() - 1  >= (2 * i) + 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool hasRightChild (struct node& heap, int i)
{
	if (heap.h_arr.size() - 1 >= ((2 * i) + 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void swapNums (struct node& heap, int big, int index)
{
	int temp = heap.h_arr[index];
	heap.h_arr[index] =  heap.h_arr[big];
	heap.h_arr[big] = temp;
}

void maxHeapify (struct node& heap, int index)
{
	int big;

		if (hasleftChild(heap, index) && heap.h_arr[(2 * index) + 1] > heap.h_arr[index])
		{
			big = (2 * index) + 1;
		}
		else 
		{
			big = index;
		}

		if (heap.h_arr[(2 * index) + 2] > heap.h_arr[big] && hasRightChild(heap, index))
		{
			big = (2 * index) + 2;
		}

		if (big != index)
		{
			swapNums(heap, big, index);
			maxHeapify(heap, big);
		}
}

void printHeap (struct node& heap)
{
	for (int i = 0; i < heap.h_arr.size(); i++)
	{
		cout << heap.h_arr[i] << " ";
	}
	cout << endl;
}

void createHeap(struct node& heap, int arr[], int size)
{
    /* Pass size as an argument because if size is caluclated in the function then we get a wrong value. Because the array is copied by value in the function as a pointer so we get the pointers size instead*/
	//int size = sizeof(arr)/sizeof(arr[0]);
	//cout << size <<   "   " ;
	
	for (int i = 0; i < size; i++)
	{
		heap.h_arr.push_back(arr[i]);
	}
    
    for (int j = (heap.h_arr.size() - 1) / 2; j >= 0; j--)
    {
		maxHeapify(heap, j);
	}
}

int extractMax (struct node& heap)
{
	int max = heap.h_arr[0];
	heap.h_arr[0] = heap.h_arr[heap.h_arr.size() - 1];
	heap.h_arr[heap.h_arr.size() - 1] = max;
	heap.h_arr.pop_back();
	maxHeapify(heap, 0);

	return max;
}

void heapSort (struct node& heap)
{
	int length = heap.h_arr.size();
	int arr[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = extractMax(heap);
	}

	for (int j = length - 1; j >= 0; j--)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
}



int main (int argc, char** args)
{
	struct node heap;
	int arr[] = {4, 2 ,1 ,8 ,3, 9, 10, 56, 67, 12};
	
	int size = sizeof(arr)/sizeof(arr[0]);

	createHeap(heap, arr, size);
	printHeap(heap);
	heapSort(heap);

	return 0;
}
