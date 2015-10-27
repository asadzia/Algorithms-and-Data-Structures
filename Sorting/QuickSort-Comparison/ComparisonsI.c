/*
*
* A program which counts the number of comparisons done by implementing quicksort in an array in C.
* In this program, the first element of the Array is chosen as the pivot. The most amount of comparisons 
* are made when the first element is used.
*
* Created by: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000

long comparisonCount = 0;

int partition(int a[], int l, int r) {
 	
 	int temp;
	int pivot = a[l];
	int i = l + 1, j;
 
	for(j = l + 1; j <= r; ++j)
	{
		if(a[j] < pivot)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			++i;
		}
	}

	temp = a[l];
	a[l] = a[i - 1];
	a[i - 1] = temp;

	return (i-1);
}
 
void quickSort (int arr[], int l, int r)
{
	int j;

	if (l < r)
	{
		comparisonCount = comparisonCount + (r - l);
		j = partition(arr, l, r);
		quickSort(arr, l, j - 1);
		quickSort(arr, j + 1, r);
	}
}

/*
* The mmain function
*/
int main ()
{
	FILE* infile;
	int arr[ARRAY_SIZE], it = 0, ch;

	infile = fopen("QuickSort.txt", "r");
	if (infile == NULL)
	{
		printf("Error in opening the file!\n");
		exit(1);
	}

	while (fscanf(infile, "%d\n", &ch) != EOF)
	{
		arr[it++] = ch;
	}
	
	quickSort(arr, 0, it - 1);

	printf("The number of comparisons are %lld\n", comparisonCount);

	fclose(infile);
	return 0;
}
