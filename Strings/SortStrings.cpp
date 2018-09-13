/* Program for sorting an array of strings */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Comparator fundtion for sorting in descending order
bool comp (string a, string b)
{
	if (a.compare(b) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main ()
{
	vector<string> vec = {"hello", "world", "I", "Am", "Alive"};

	// descending order
	// sort(vec.begin(), vec.end(), comp);

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}

	return 0;
}
