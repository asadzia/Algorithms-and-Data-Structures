/* Program to find the minimum window if a string is contained in another string */

#include <iostream>
#include <string>
#include <vector>
#include <climits>

#define MAX_CHAR 256

using namespace std;

bool checkContains (string str, string pattern)
{
	vector<int> patternVector (MAX_CHAR, 0);
	vector<int> strVector (MAX_CHAR, 0);
	int count = 0;
	int patternLength = pattern.length();
	int windowLength = 0;
	int start = 0;
	int start_index = -1;
	int min_len = INT_MAX;

	if (pattern.length() > str.length())
	{
		return false;
	}

	for (int i = 0; i < pattern.length(); ++i)
	{
		patternVector[pattern[i]]++;
	}

	for (int i = 0; i < str.length(); ++i)
	{
		// count occourence of character in the string
		strVector[str[i]]++;

		if (patternVector[str[i]] > 0)
		{
			if (strVector[str[i]] <= patternVector[str[i]])
			{
				count++;	
			}
		}

		// window found. Now Refine the Window
		if (count == patternLength)
		{     		
     		// Refining the Window: Remove any characters occurring more than the pattern and remove useless characters
			while(strVector[str[start]] > patternVector[str[start]] || patternVector[str[start]] == 0)
			{
				if (strVector[str[start]] > patternVector[str[start]])
				{
					strVector[str[i]]--;
				}
				start++;
			}

			windowLength = i - start + 1;

			// for each character after the FIRST time all letters of a pattern are found:
			if (min_len > windowLength)
			{
				min_len = windowLength;
				start_index = start;
			}
		}
	}

	// If the pattern is not found, return false.
	if (start_index == -1)
	{
		return false;
	}
	
	// minimum Window Length
	cout << str.substr(start_index, min_len) << endl;

	return true;

}

int main (int argc, char** args)
{
	string str = "zaaskzaa";
	string pattern = "zsk";

	checkContains(str, pattern);

	return 0;
}

