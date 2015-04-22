/*
*
* An implementation of Kadanes's Algorithm (Maximum sub-array) in C
*
* Created by: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

/*
* A function to get the maximum number
*/
int getMax (int x, int y) 
{
	if (x < y)
	{
		return y;
	}
	else
	{
		return x;
	}
}

/*
* The function to get the maximum subarray along with the indices
*/
int maxSubarray (int arr[], int size)
{
	int cur_max = arr[0], max_until_now = arr[0], i, cur_index, start_index, end_index;
	
	for (i = 1; i < size; i++)
	{
		if (cur_max < 0)
		{
			cur_index = i;
		}
		cur_max = getMax(arr[i], cur_max + arr[i]);

		if (max_until_now < cur_max)
		{
			start_index = cur_index;
			max_until_now = getMax(cur_max, max_until_now);
			end_index = i;
		}
	}

	for (i = start_index; i <= end_index; i++) 
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return max_until_now;
}

/*
* The main function
*/
int main () 
{
	int arr[] = {-2, -3, 1, 5, -1, -2, 4, -5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int result = maxSubarray (arr, size);
	printf("Result: %d\n", result);
	return 0;
}
