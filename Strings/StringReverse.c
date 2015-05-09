/*
*
* A string reverse algorithm in C using O(n) time.
*
* Created by: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse (char str[])
{
	int i, j;

	j = strlen(str) - 1;
	i = 0;

	while (i < j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		--j;
		++i;
	}
}

int main ()
{
	char str[20] = "Hello World!";
	printf("Original String: %s\n", str);
	reverse(str);
	printf("Reversed String: %s\n", str);
	return 0;
}
