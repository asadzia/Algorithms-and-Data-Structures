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

/*
RECURSIVE SOLUTION

#include <iostream>
#include <string>

using namespace std;

void reverseString (string str, int x, int y)
{
  if (x > y)
  {
        cout << str << endl;
    return;
  }

    char temp = str[x];
    str[x] = str[y];
    str[y] = temp;
    reverseString(str, x+1, y-1);
}

int main ()

{
  string str = "HEllo";
  reverseString(str, 0, str.length() - 1);
  return 0;
}

*/
