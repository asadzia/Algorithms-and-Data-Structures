/*
*
* A program to check if a string is a palindrome in C.
*
* Created By: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* A function to reverse a string
*/
void reverse (char str[])
{
	int i = 0;
	int j = strlen(str) - 1;

	while (i < j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		++i;
		--j;
	}
}

/*
* A function to check if a string is a palindrome
*/
void CheckPalindrome (char str[])
{
	char temp[100];
	strcpy(temp, str);
	reverse(str);
	if (strcmp(str, temp) == 0)
	{
		printf("%s is a Palindrome!\n", str);
	}
	else
	{
		printf("%s is not a Palindrome!\n", str);
	}
}

/*
* The main function
*/
int main ()
{
	char str[100] = "Hello World";
	char str2[100] = "AsaddasA";
	CheckPalindrome(str);
	CheckPalindrome(str2);
	return 0;
}
