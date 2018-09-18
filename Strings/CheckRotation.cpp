/* A Program to check if strings are rotations of each other or not */

#include <iostream>
#include <string>

using namespace std;

int main ()
{
	// concatenate string one with string one and check if string two is a substring

	string str = "ABCDE";
	string str1 = "DEABC";

	string concatenate = str + str;

	if (concatenate.find(str1) != string::npos)
	{
		cout << "String 2 is a rotation of String 1" << endl;
	}
	else
	{
		cout << "Not a rotation" << endl;
	}

	return 0;
}
