/* Test: 1.0 
   Author: Asad Zia
   Version: 1.0
   Description: Code for finding strings in freetext if the strings in the freetext have one char missing compared to the search string. This
   				check is only carried out if the normal searchString is not found in the freeText.
   				Example: freetext: 2345 and searchString: 12345 gives True. (because 12345 is not present in freetext, the program searches for
   				variations of the searchString with one char missing). 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkStrings (string _str1FreeText, string _str2Search)
{
	/* Carry out a normal string.Find() check */
	if ((_str1FreeText.find(_str2Search)) != string::npos)
	{
		return true;
	}

	/* variable declarations */
	vector<string> variations;
	vector<string>::iterator it;
	int index;

	/* Check for variations */
	
	for (int it = 0; it < _str2Search.length(); ++it)
	{
		index = it;

		if (index == 0)
		{
			variations.push_back(_str2Search.substr(1));
		}
		else if (index == _str2Search.length() - 1)
		{
			variations.push_back(_str2Search.substr(0, _str2Search.length() - 1));
		}
		else
		{
			string temp = "";
			temp = temp + _str2Search.substr(0, it);
			temp = temp + _str2Search.substr(it + 1);
			variations.push_back(temp);
		}
	}

	for (it = variations.begin(); it != variations.end(); it++)
	{
		if ((_str1FreeText.find(*it)) != string::npos)
		{
			return true;
		}
	}

	return false;
}

int main (int argc, char** args)
{
	string freeText = "Hello. I am Human. 2345. Auf WiederSehen.";
	string search = "12345";

	if  (checkStrings(freeText, search))
	{
		cout << "Matched " << search << endl;
	}
	else
	{
		cout << "No Match for " << search << endl;
	}

	return 0;
}
