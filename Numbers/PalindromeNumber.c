/*
*
* A program to check if a number is a palindrome in C.
*
* Created by: Asad Zia.
*/

#include <stdio.h>
#include <stdlib.h>

/*
* The function to check if a number is a palindrome.
*/
void checkPalindrome (int n)
{
	int temp = n, temp2 = 0;

	while (temp != 0)
	{
		temp2 = temp2 * 10;
		temp2 = temp % 10 + temp2;
		temp = temp / 10;
	}

	if (temp2 == n)
	{
		printf("The number %d is palindrome!\n", n);
	}
	else
	{
		printf("The number %d is not a palindrome!\n", n);
	}
}

/*
* The main function
*/
int main ()
{
	int n;

	printf("Please enter a number:\n");
	scanf("%d", &n);
	
	checkPalindrome(n);
	return 0;
}
