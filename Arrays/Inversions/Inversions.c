/*
*
* A program for finding the number of inversions in an array.
*
*
* Created by: Asad Zia
*
*/

#include <stdio.h>
#include <stdlib.h>

long merge (int arr[], int l, int m, int r)
{
	/* declare an array with the same size as arr[] */
	int arr2[r + 1]; 
	int i, j, k;
	/* we have to use a long since the number of inversions is very large.
	Since the number of inversions is large, it causes an overflow for the int type */
	long count = 0;

	/* make two subarrays */
	for (i = l; i <= m - 1; ++i) 
	{
		arr2[i] = arr[i];
	}

	for (j = m; j <= r; ++j)
	{
		arr2[j] = arr[j];
	}

	k = l;
	i = l;
	j = m;

	while ((i <= m - 1) && (j <= r) && (k <= r))
	{
		if (arr2[i] <= arr2[j])
		{
			arr[k++] = arr2[i++];
		}
		else
		{
			arr[k++] = arr2[j++];
			count = count + (m - i);
		}
	}

	/* copy remaining elements in the array in case they are left */
	while (i <= m - 1)
	{
		arr[k++] = arr2[i++];
	}

	while (j <= r)
	{
		arr[k++] = arr2[j++];
	}

	return count;
}

long mergeSort (int arr[], int l, int r)
{
	long inversion_count = 0, m;

	if (l < r)
	{
		/* the array is divided into two parts */
		m = (l + r) / 2;
		
		/* call mergeSort() for each subarray */
		inversion_count = mergeSort(arr, l, m);
		inversion_count += mergeSort(arr, m + 1, r);
		
		/* merge the arrays together and add the count for inversions between the two subarrays */
		inversion_count += merge(arr, l, m + 1, r);
	}
	return inversion_count;
}

int main () 
{
	FILE* infile;
	int i = 0, it;
	int arr[100000];

	infile = fopen("IntegerArray.txt", "r");
	if (infile == NULL)
	{
		printf("Error in opening file!\n");
		exit(1);
	}

	while (fscanf(infile, "%d\n", &it) != EOF)
	{
		arr[i++] = it;
	}

	printf("Number of inversions: %lld\n", mergeSort(arr, 0, i-1));

	fclose(infile);
	return 0;
}
