/*Merge Sort*/

#include <iostream>

#define SIZE 10

using namespace std;

void mergeArrays(int arr[SIZE], int temp [SIZE], int l, int r)
{
	int l_left = l;
	int l_right = (l + r)/2;
	int r_left = l_right + 1;
	int r_right = r;
	int index = l_left;

    // Merge the two parts into temp[].
	while (l_left <= l_right && r_left <= r_right)
	{
		if (arr[l_left] <= arr[r_left])
		{
			temp[index] = arr[l_left];
			l_left++;
		} 
		else
		{
			temp[index] = arr[r_left];
			r_left++;
		}
		index++;
	}

	// copy over the remainder of the elements
	if (l_left <= l_right)
	{
		while(l_left <= l_right)
		{
			temp[index] = arr[l_left];
		    ++index;
		    l_left++;
		}
	}
	if (r_left <= r_right)
	{
		while (r_left <= r_right)
		{
			temp[index] = arr[r_left];
			++index;
			r_left++;
		}
	}
	
	//Assign data from temp array to original array
	
	for (int i = 0; i <= r_right; ++i)
	{
	    arr[i] = temp[i];
	}
	
}



void mergeSort(int arr[SIZE], int temp [SIZE], int l, int r)
{
	if (r > l)
	{
		int middle = (l + r)/2;
		mergeSort(arr, temp, l, middle);
		mergeSort(arr, temp, middle + 1, r);
		mergeArrays(arr, temp, l, r);
	}
	return;
}


int main (int argc, char** args)
{
	int arr[] = {5,8,1,3,9,4,2,8,4,11};
	//int size = sizeof(arr)/sizeof(arr[0]);
	int temp[SIZE];
	int l = 0;
	int r = SIZE - 1;

	mergeSort(arr, temp, l, r);

	for (int i = 0; i < SIZE; i++)
	{
		cout << temp[i] << " " << endl;
	}

	return 0;
}
