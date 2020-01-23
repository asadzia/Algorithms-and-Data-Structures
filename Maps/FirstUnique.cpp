/* A program to find the first unique integer in an array */

#include <bits/stdc++.h> 
using namespace std; 
 
// Note: Use long long int for latge numbers.
// Unordered map used because it uses hashing with O[1)
// Normal maps use red black trees.
int firstNonRepeating(int arr[], int n) 
{ 
    // Insert all array elements in hash 
    // table 
    unordered_map<int, int> mp; 
    for (int i = 0; i < n; i++) 
        mp[arr[i]]++; 
  
    // Traverse array again and return 
    // first element with count 1. 
    // When the array is traversed again, the first int which has 
	// a value of 1 in the map will be the result.
    for (int i = 0; i < n; i++) 
        if (mp[arr[i]] == 1) 
            return arr[i]; 
    return -1; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 9, 4, 9, 6, 7, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << firstNonRepeating(arr, n); 
    return 0; 
} 

/* ALTERNATE

#include <iostream>
#include <map>
#include <utility>

using namespace std;

int findUnique (int arr[], int size)
{
	map<int, pair<int, int> > track;
	map<int, pair<int, int> >::iterator it;

	for (int i = 0; i < size; ++i)
	{
		if ((it = track.find(arr[i])) != track.end())
		{
			it->second.second++;
		}
		else
		{
			track[arr[i]] = pair<int, int>(i, 1);
		}
	}

  it = track.begin();
	int result = it->first;
	int idx = 99999999;

	for (it = track.begin(); it != track.end(); it++)
	{
		if (it->second.second == 1 && it->second.first < idx)
		{
			idx = it->second.first;
			result = it->first;
		}
	}

	return result;
	return 0;
}

int main ()
{
	int arr[] = {1,9,1,4,5,5,6,2,6,6,6};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout << findUnique(arr, size) << endl;

	return 0;
}
*/


/*
ALTERNATIVE COMPARATOR SOLUTION

#include <iostream>
#include <map>

using namespace std;

struct node
{
    int value;
    int index;
};

struct mycomp
{
  // STD::MAP does not support comparison by values
    bool operator() (const int &x, const int &y) const
    {
        return x.index < y.index;
    }
};

int main ()
{
    int arr[] = {21, 12, 12, 32,32, 45, 12, 21, 34, 45, 90};
    int size = sizeof(arr)/sizeof(arr[0]);

    map<int, node, mycomp> temp;

    for (int i = 0; i < size; i++)
    {
        if (temp.find(arr[i]) != temp.end())
        {
            temp[arr[i]].value = temp[arr[i]].value + 1;
        }
        else
        {
            node x;
            x.value = 1;
            x.index = i;
            temp[arr[i]] = x;
        }
    }

    cout << "First unique number: " <<  << endl;

    return 0;

}
*/
