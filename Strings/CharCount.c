/* An implementation for counting the number of similar characters in C.
	
	By: Asad Zia
*/


#include <stdio.h>

int main () 
{
	char str [100];
	char temp[100];
	int i, j, count = 0, it = 0, flag = 0;
	fgets(str, 100, stdin);

	for (i = 0; str[i] != '\n'; i++) 
	{
		for (j = 0; str[j] != '\n'; j++) 
		{
			if (str[i] == str[j]) 
			{
				count++;
			}
		}
		
		for (j = 0; j < 100; j++)
		 {
			if (str[i] == temp[j]) 
			{
				count = 0;
				flag = 1;
				break;
			}
			else
			{
				flag = 0;
			}
		}
		
		if (flag == 0)
		 {
			temp[it] = str[i];
			printf("%d %c\n",count, str[i]);
			count = 0;
			it++;
		}
	
	}
	return 0;
}
