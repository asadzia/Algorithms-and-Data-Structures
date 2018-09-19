/* Program to check if two strings a re anagrams of each other */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_CHAR 256

/* Two solutions:
- First: Sort both strings and compare. Complexity: O(nlogn)
- Second: count chars in both strings and compare
*/

int main ()
{
	bool anagrams = true;

	string str1 = "tutorial cup";
	string str2 = "cup tutorial";

	vector<int> vc1 (MAX_CHAR, 0);
	vector<int> vc2 (MAX_CHAR, 0);

	if (str1.length() != str2.length())
	{
		cout << "Not anagrams" << endl;
    anagrams = false;
	}
	else
	{
		for (int i = 0; i < str1.length(); i++)
		{
			vc1[str1[i]]++;
			vc2[str2[i]]++;
		}

		for (int i = 0; i < MAX_CHAR; ++i)
		{
			if (vc1[i] != vc2[i])
			{
				cout << "Not Anagrams" << endl;
				anagrams = false;
				break;
			}			
		}

		if (anagrams)
		{
			cout << "Anagrams! Yes! " << endl;
		}
	}

	return 0;
}
