/*
Description: A program to check if all characters are unique in a string.
			 Implemented in C++.
Version:	 1.0
Author:		 Asad Zia
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void checkUnique (string str)
{
	vector<int> uniqueChars(4, 0);

	for (int i = 0; i < str.length(); ++i)
	{
		++uniqueChars[str[i]];
		if (uniqueChars[str[i]] > 1)
		{
			cout << "Not unique" <<  endl;
			return;
		}
	}
	cout << "Unique" << endl;
}

int main ()
{
	cout << "Begin Execution" << endl;
	checkUnique("asdfghjqwertyqu");
	cout << "End Execution" << endl;
	return 0;
}
