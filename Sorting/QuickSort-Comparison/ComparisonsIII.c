/*
*
* A program which counts the number of comparisons done by implementing quicksort in an array in C.
* In this program, the median element from the set {array[firstElement], array[middle], array[last]}
* is used as the pivot. This gives the least number of comparisons, and hence proves to be the fastest.
*
* Created by: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000

/* declaring global count variable */
long comparisonCount = 0;

/*
* The comparator function used in qsort
*/
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

/*
* The patitioning algorithm
*/
int partition(int a[], int l, int r) {
		
	int p, temp;

	/* finding the median in the array */
	int mid = (r - l) / 2 + l;
	int arr[] = {a[l], a[mid], a[r]};

	qsort(arr, 3, sizeof(arr[0]), cmpfunc);

	if (arr[1] == a[l])
	{
		p = l;
	}
	else if (arr[1] == a[r])
	{
		p = r;
	}
	else
	{
		p = mid;
	}

	temp = a[p];
	a[p] = a[l];
	a[l] = temp;

	/* set the median as the pivot */
	int pivot = arr[1];
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
 
/* 
* The main QuickSort function
*/
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
