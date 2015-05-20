/*
*
* A program to find the intersection and union of sorted arrays
*
*
* Created by: Asad Zia
*/

#include <stdio.h>

void unionArray(int arr[], int arr2[], int size1, int size2)
{
	int i = 0, j = 0;
 
	while (i < size1 && j < size2)
	{
		if (arr[i] < arr2[j])
		{
			printf("%d ", arr[i]);
			i++;
		}

		else if (arr[i] > arr2[j])
		{
			printf("%d ", arr2[j]);
			j++;
		}

		else /* arr[i] == arr[j] */
		{
			printf("%d ", arr[i]);
			i++;
			j++;
		}
	} 

	while (i < size1)
	{
		printf("%d ", arr[i]);
		i++;
	}

	while (j < size2)
	{
		printf("%d ", arr2[j]);
		j++;
	}

	printf("\n");
}

/*
* The function for finding the intersection
*/
void intersection (int arr[], int arr2[], int size1, int size2)
{
	int i = 0, j = 0;
 	
 	while (i < size1 && j < size2)
 	{
 		if (arr[i] < arr2[j])
 		{
 			i++;
 		}
 		else if (arr[i] > arr2[j])
 		{
 			j++;
 		}
 		else
 		{
 			printf("%d ", arr[i]);
 			i++;
 			j++;
 		}
 	}
 	printf("\n");
}

/*
* The main function
*/
int main ()
{
	int arr[] = {1,2,3,5,7,9};
	int arr2[] = {2,3,5,7};

	int size1 = sizeof(arr)/sizeof(arr[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);

	printf("Union:\n");
	unionArray(arr, arr2, size1, size2);
	printf("Intersection:\n");
	intersection(arr, arr2, size1, size2);
	return 0;
}
