/*
Description: A program which inserts a number in an another number between two indexes of the first number.
			 Implemented in C++.
Version:	 1.0
Author:		 Asad Zia
*/

#include <iostream>
#include <climits>

using namespace std;

void InsertNumber (int numOne, int numTwo, int i, int j)
{
	for (int k = j; k >= i; --k)
	{
		numOne = numOne & ~(1 << k);
	}

	numOne = numOne | (numTwo << i);

	for (int m = sizeof(int) * CHAR_BIT; m >= 0; --m)
	{
	    if ((numOne & (1 << m)) > 0)
		    cout << "1";
		else
		    cout << "0";
	}
}

int main ()
{
	cout << "Begin Execution" << endl;
	InsertNumber(1024, 19, 2, 6);
	cout << "\nEnd Execution" << endl;
	return 0;
}
