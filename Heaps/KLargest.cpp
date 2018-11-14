/*
A program to print the k largest elements in an array
*/

#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

void printKLargest (int arr[], int size, int k)
{
	priority_queue<int, vector<int>, less<int>> q;

	for (int i = 0; i < size; ++i)
	{
		q.push(arr[i]);
	}

	for (int i = 0; i < k; i++)
	{
		int x = q.top();
		q.pop();

		cout << x << endl;
	}
}

int main ()
{
	int arr [] = {435, 789, 34, 98, 13, 634, 6};

	printKLargest(arr, 7, 3);

	return 0;
}
