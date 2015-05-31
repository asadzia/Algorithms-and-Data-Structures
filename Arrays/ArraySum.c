/*
*
* A program to check if two integers in an array equal a number X.
*
* Created by: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

/*
* The simple partitioning function for the array
*/
int partition (int arr[], int l, int r)
{
	int pivot = l, t;
	int i = l;
	int j = r;

	while (i < j)
	{
		while (arr[pivot] >= arr[i] && i < r)
		{
			i++;
		}

		while (arr[pivot] < arr[j])
		{
			j--;
		}

		if (i < j)
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}

	t = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = t;

	return j;
}

/*
* The quicksort function
*/
void quicksort (int arr[], int l, int r)
{
	int j;
	if (l < r)
	{
		j = partition(arr, l, r);
		quicksort(arr, l, j-1);
		quicksort(arr, j+1, r);
	}
}

/*
* The function to check the sum of two numbers
*/
int checkSum (int arr[], int size, int x)
{
	int l = 0, r = size - 1;

	quicksort(arr, 0, size - 1);

	while (l < r)
	{
		if (arr[l] + arr[r] == x)
		{
			printf("The numbers %d and %d equal %d\n", arr[l], arr[r], x);
			return 0;
		}

		else if (arr[l] + arr[r] < x)
		{
			l++;
		}

		else
		{
			r--;
		}
	}
	printf("The numbers do not exist in this array!\n");
	return 1;
}

/*
* The main function
*/
int main ()
{
	int sum = 97;
	int arr[] = {4, 7, 2, 8, 1, 3, 9, 76, 21, 12};
	int size = sizeof(arr)/sizeof(arr[0]);
	checkSum(arr, size - 1, sum);
	return 0;
}
