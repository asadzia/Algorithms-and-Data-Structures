/* An implementation of the quicksort algorithm
	
	By: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

void quickSort( int[], int, int);
int partition( int[], int, int);

/*
* The main function
*/
int main() 
{
	int a[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};

	int i;
	printf("\n\nUnsorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

	quickSort( a, 0, 8);

	printf("\n\nSorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

  return 0;
}

/*
* The main quicksort algorithm
*/
void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	 /* divide and conquer */
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
}

/*
* The partitioning algorithm
*/
int partition( int a[], int l, int r) {
   int pivot, i, j, t;
    
    pivot = l;
    i = l;
    j = r;

    while (i < j)
    {
        while (a[i] <= a[pivot] && i < r)
        {
          i++;
        } 

        while (a[j] > a[pivot])
        {
          j--;
        }

        if (i < j) {
          t = a[i];
          a[i] = a[j];
          a[j] = t;
        }
    }

    t = a[pivot];
    a[pivot] = a[j];
    a[j] = t;

    return j;
}

