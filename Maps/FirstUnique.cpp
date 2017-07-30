/* A program to find the first unique integer in an array */

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
