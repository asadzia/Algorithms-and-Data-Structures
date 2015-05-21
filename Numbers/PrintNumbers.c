/*
* A program to print numbers from one to n without using a loop in C.
*
* Created by: Asad Zia.
*/

#include <stdio.h>

void printing (int n)
{
	if (n > 0)
	{
		printing(n - 1);
		printf("%d \n", n);
	}
}

int main ()
{
	printing(100);
	return 0;
}
