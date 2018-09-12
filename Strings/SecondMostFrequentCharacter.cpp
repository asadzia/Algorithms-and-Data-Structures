/* A program to find the second most frequent character in a string */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

char secondMostFrequentCharacterMap (string str)
{
	map<char, int> mp;

	for (int i = 0; i < str.length(); ++i)
	{
		if (mp.find(str[i]) == mp.end())
		{
			mp[str[i]] = 1;
		}
		else
		{
			mp[str[i]] += 1;
		}
	}

	map<char, int>::iterator it;
	int first = 0, second = 0;
  	char result1, result2;

	for (it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second > first)
		{
     		second = first;
			first = it->second;
			result2 = result1;
      		result1 = it->first;
		}

		if (it->second < first && it->second > second)
		{
      result2 = it->first;
			second = it->second;
		}
	}

	return result2;
}


char secondMostFrequentCharacterVector (string str)
{
	vector<int> vc (256, 0);
	int first = 0, second = 0;
	int result1, result2;

	for (int i = 0; i < str.length(); i++)
	{
		vc[str[i]] += 1;
	}

	for (int i = 0; i < vc.size(); ++i)
	{
		if (first < vc[i])
		{
			second = first;
			result2 = result1;
			first = vc[i];
			result1 = i;
		}
		
		if (second < vc[i] && first > vc[i])
		{
			second = vc[i];
			result2 = i;
		}
	}

	return (char)result2; 	
}

int main ()
{
	string str = "Hello World";

	cout << secondMostFrequentCharacterVector(str) << endl;

	return 0;
}
