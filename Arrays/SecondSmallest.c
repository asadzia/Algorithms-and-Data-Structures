/*
*
* An algorithm to find the second Smallest element in an array in C.
*
* Created by: Asad zia
*
*/

#include <stdio.h>
#include <limits.h>

void findVal (int arr[], int size)
{
	int i, temp = INT_MAX, temptwo = INT_MAX;

	for (i = 0; i < size; i++)
	{
		if (arr[i] < temp)
		{
			temptwo = temp;
			temp = arr[i];
		}

		else if (arr[i] < temptwo && arr[i] != temp)
		{
			temptwo = arr[i];
		}
	}
	printf("Largest: %d\nSecond Largest: %d\n", temp, temptwo);
}

int main ()
{
	int arr[] = {1, 2, 3, 7, 9, 44, 23, 87};
	int size = sizeof(arr)/sizeof(arr[0]);
	findVal(arr, size);
	return 0;
}
