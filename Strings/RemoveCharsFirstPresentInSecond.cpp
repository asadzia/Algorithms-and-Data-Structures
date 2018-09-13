/* Remove characters from first string which are present in the second string */

#include <iostream>
#include <string>
#include <vector>

#define CHAR_COUNT 256

using namespace std;

string removeChars (string a, string b)
{
	vector<int> vc (CHAR_COUNT, 0);
	string result = "";

	for (int i = 0; i < b.length(); ++i)
	{
		vc[b[i]] += 1;
	}

	for (int i = 0; i < a.length(); ++i)
	{
		if (vc[a[i]] > 0)
		{
			continue;
		}

		result += a[i];
	}

	return result;
}

int main (int argc, char** args)
{
	string a = "computer";
	string b = "cat";

	cout << removeChars(a, b) << endl;

	return 0;
}
