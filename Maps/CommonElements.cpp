/* A program to find the common elements between two arrays */

#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main ()
{
	int arr1[] = {1,2,3,4,5,6,7,8,9,0};
	int arr2[] = {2,2,2,2,5,2,2,2,2,1,2};

	map<int, int> vals;

	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);

	map<int, int>::iterator it;

	for (int i = 0; i < size1; i++)
	{
		if ((it = vals.find(arr1[i])) == vals.end())
		{
			vals[arr1[i]] = 1;
		}
	}

		for (int i = 0; i < size2; i++)
	{
		if ((it = vals.find(arr2[i])) != vals.end())
		{
			it->second++;
		}
	}

	for (it = vals.begin(); it != vals.end(); it++)
	{
		if (it->second > 1)
		{
			cout << "Common: " << it->first << endl;
		}
	}

	return 0;
}
