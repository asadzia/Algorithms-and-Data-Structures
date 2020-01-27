/*
* A function to rotate a string in C. Rotates to the right!
*
*
*
* Created by: Asad zia
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse (char* str, int start, int end)
{
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void rotate (char* str, int k)
{
	int j = strlen(str);
	reverse(str, 0, j - 1);
	reverse(str, 0, k - 1);
	reverse(str, k, j - 1);
}

int main ()
{
	char str[20] = "DeadBones";
	printf("Original String: %s\n", str);
	rotate(str, 2);
	printf("Rotated String: %s\n", str);
	return 0;
}
