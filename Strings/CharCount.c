/* An implementation for counting the number of similar characters in C.
	
	By: Asad Zia
*/



#include <stdio.h>

/*
* A fcuntion to count the number of characters
*/
void countChars (char* str)
{
	int max = 0, i;
	char max_char;
	char temp = str[0];
	int count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (temp == str[i])
		{
			count++;
		}
		else
		{
			if (count > max)
			{
				max = count;
				max_char = temp;
			}

			count = 1;
			temp = str[i];
		}
	}

	printf("Maximum recurring character in the string is %c. It occurs %d times.", max_char, max);
}

/*
* The main function
*/
int main ()
{
	char* str = "aabbbccccddee";
	countChars(str);
	return 0;
}
