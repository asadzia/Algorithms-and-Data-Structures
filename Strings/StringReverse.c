/* An implementation of a basic string reverse algorithm.
	
	By: Asad Zia
*/

#include <stdio.h>
#include <stdlib.h>

/*
* The function for reversing the string
*/
void do_rev (char* x) {
	char* ptr;
	int i, count = 0;

	while (1) {
		if (*x == '\0') {
			break;
		}
		x++;
		count++;
	}
		x--;

	for (i = 0; i < count; i++) {
		*ptr = *x;
		printf("%c", *ptr);
		x--;
		ptr++;
	}
}

/*
* The main function
*/
int main () {
	char *str = "Hello";
	char* str_result;
	printf("%s\n", str);
	do_rev(str);
	return 0;
}
