/*
*
* A program to convert a decimal number to a binary representation
*
* Created by: Asad Zia
*/

#include <stdio.h>

void DtoB (int x)
{
	int arr[100], i = 0, j;

	while (x != 0)
	{
		arr[i] = x % 2;
		x = x / 2;
		++i;
	}

	for (j = i - 1; j >=0; --j)
	{
		printf("%d", arr[j]);
	}
}

int main ()
{
	int number = 4;
	DtoB(4);
	return 0;
}
