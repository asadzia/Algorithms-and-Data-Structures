/*
Description: A program in which, given two strings, the anagram of the second string is a substring of the first string.
			 To implement this, the idea is taken from the Rabin Karp Algorithm for strings.
			 Implemented in C++.
Version:	 1.0
Author:		 Asad Zia
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string checkAnagramString (string first, string second)
{
	int lengthOfPatternString = second.length();
	int sum_one = 0, sum_two = 0, index = 0;
	
	for (int k = 0; second[k] != '\0'; ++k)
	{
		sum_two = sum_two + second[k];
	}

	for (int i = 0; first[i] != '\0'; ++i)
	{
		if (i < lengthOfPatternString)
		{
			sum_one = sum_one + first[i];
			continue;
		}
		
		if (sum_one == sum_two)
			{
			    break;
			}

		sum_one = sum_one - first[index] + first[i];
		index++;
	}

	/* This is written outside the loop because the last index of the TEXT string cannot be checked inside the loop */
	if (sum_one == sum_two)
		{
		    stringstream message;
		    message << "Pattern found starting from position " << index;
			return message.str();
		}

	return "Pattern not found!";
}

int main ()
{
	string wordOne = "HelloWorld";
	string wordTwo = "dorl";
	cout << "Begin Execution" << endl;
	cout << checkAnagramString(wordOne, wordTwo) << endl;
	cout << "End Execution" << endl;
	return 0;
}

