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


#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

// First int is the index and second is the count of the character

void print (vector<pair<int, int>> vc)
{
  for (int i = 0; i < vc.size(); ++i)
  {
    cout << vc[i].second;
  }
}

int main ()
{
	vector<pair<int, int>> vc (CHAR_MAX, make_pair(0, 0));

	string str =  "tutorial cup";

	for (int i = 0; i < str.length(); ++i)
	{
		vc[str[i]].second++;
		if (vc[str[i]].second == 1)
		{
			vc[str[i]].first = i;
		}
	}

	char min_char;
	int index = INT_MAX;

	for (int i = 0; i < CHAR_MAX; i++)
	{
		if (vc[i].second == 1)
		{
			if (vc[i].first < index)
			{
				min_char = (char)i;
				index = vc[i].first;
			}
		}
	}

	if (index == INT_MAX)
	{
		cout << "No non-repeating character found" << endl;
	}
	else
	{
		cout << min_char << " found at position " << index << endl;
	}

	return 0;
}

*/
