/*
Description: A program which prints all the combinations of parenthesis for n-pairs.
			 Implemented in C++.
Version:	 1.0
Author:		 Asad Zia
*/

#include <iostream>
#include <string>

using namespace std;

void printParenthesis (string str, int x, int y, int n)
{
	if (x == n && y == n)
	{
		cout << str << endl;
		return;
	}
	else
	{
		if (x < n)
		{
			printParenthesis(str + "(", x + 1, y, n);
		}

		if (y < x)
		{
			printParenthesis(str + ")", x, y + 1, n);
		}
	}
}

int main ()
{
	cout << "Begin Execution" << endl;
	printParenthesis("", 0, 0, 3);
	cout << "End Execution" << endl;
	return 0;
}
