/* Program to remove duplicates from a string */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define CHAR_COUNT 256

int main ()
{
	string str = "Hello World";
	string result = "";

	vector<int> vc (CHAR_COUNT, 0);

	for (int i = 0; i < str.length(); i ++)
	{
		vc[str[i]] += 1;
	}

	for (int i = 0; i < str.length(); ++i)
	{
		if (vc[str[i]] > 0)
		{
			result += str[i];
      // if a character has occured then set it to 0 to avoid reading it again
      vc[str[i]] = 0;
		}
	}

	cout << result << endl;

	return 0;
}
