/*
*
* Power calculation implemented in C
*
* Created by: Asad zia
*/

#include <stdio.h>
#include <stdlib.h>

int main () 
{
	int power, i;
	float base, b = 1;
	
	printf("Please enter the base number:\n");
	scanf("%f", &base);
	
	printf("Please enter the power:\n");
	scanf("%d", &power);
	
	/* handles positive power case */
	if (power > 0) 
	{
		for (i = 0; i < power; i++)
		{
			b = b * base;
		}
		printf("Answer: %f", b);
	}
	/* handles negative power case */
	else
	{
		power = -power;
		for (i = 0; i < power; i++)
		{
			b = b * base;
		}
		b = 1.0 / b;
		printf("Answer: %f", b);
	}
		
	return 0;
}
