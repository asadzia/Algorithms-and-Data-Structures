/*
Description: A program which checks for the first non-repeating character in a string.
			 Implemented in C++.
Version:	 1.0
Author:		 Asad Zia
*/

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <climits>

using namespace std;

void first_NonRepeatingChar (string word)
{	
	map <char, pair<int, int> > table;

	bool flag = false;

	for (int i = 0; i < word.length(); ++i)
	{
		if (table[word[i]].first == 0)
		{
			table[word[i]].first++;
			table[word[i]].second = i;
			continue;
		}
		table[word[i]].first++;
	}

	for (map <char, pair<int, int> >::iterator it = table.begin(); it != table.end(); ++it)
	{
		if (it->second.first == 1)
		{
			cout << "First Non-Repeating Character: " << word[it->second.second] << endl;
			flag = true;
			break;
		}
	}
	
	if (flag == false)
	{
	    cout << "No Non-Repeating Character found!" << endl;
	}
}

int main ()
{
	cout << "Begin Execution" << endl;
	string word = "aabbccddeettuppooii";
	first_NonRepeatingChar(word);
	cout << "End Execution" << endl;
	return 0;
}

/*
[COMMENT: This approach is suitable for shorter strings and uses an O(n) approach.
 However, for a longer string, it would take time. It is much better to store the
 index of the string by traversing it once and then traverse the Count Map instead]

void first_NonRepeatingChar (string word)
{
	map<char, int> table;
	bool flag = false;

	for (int i = 0; i < word.length(); ++i)
	{
		table[word[i]]++;
	}

	for (int i = 0; i < word.length(); ++i)
	{
		if (table[word[i]] == 1)
		{
			cout << "First Non-Repeating Character: " << word[i] << endl;
			flag = true;
			break;
		}
	}
	
	if (flag == false)
	{
	    cout << "No Non-Repeating Character found!" << endl;
	}
}
*/
