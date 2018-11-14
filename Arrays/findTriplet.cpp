/*
Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.
Example:

Input: arr[] = {3, 1, 4, 6, 5}
Output: True
There is a Pythagorean triplet (3, 4, 5).

Input: arr[] = {10, 4, 6, 12, 5}
Output: False
There is no Pythagorean triplet.
*/

#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

bool findTriplet (int arr[], int size)
{
	for(int i = 0 ; i < size; i++)
	{
		arr[i] = arr[i] * arr[i];
	}

	sort(arr, arr + size);

	int l = 0;
	int r = size - 1;

	for (int i = size - 1; i >= 0; --i)
	{
		while (l < r)
		{
			if (arr[l] + arr[r] == arr[i])
			{
				return true;
			}

			if (arr[l] + arr[r] < arr[i])
			{
				l++;
			}
			else
			{
				r--;
			}
		}
	}
	return false;
}

int main ()
{
	int arr[] = {3, 1, 4, 6, 5}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    findTriplet(arr, arr_size)? cout << "Yes": cout << "No"; 
    return 0; 
}
