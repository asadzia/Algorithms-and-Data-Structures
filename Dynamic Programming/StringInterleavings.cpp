/* Given two strings s1 and s2, write a function that will print all the interleavings of the given two strings.

Here interleaving string is a string which has the same order that of individual strings.

In the below example, we can see that 'A' will always comes before 'B' and 'C' will always comes before 'D'

Example
INPUT
s1 = "AB"
s2 = "CD"

OUTPUT
ABCD, ACBD, ACDB, CABD, CADB, CDAB

 */

#include <iostream>
#include <string>

using namespace std;


/* Given two strings s1 and s2, write a function that will print all the interleavings of the given two strings.

Here interleaving string is a string which has the same order that of individual strings.

In the below example, we can see that 'A' will always comes before 'B' and 'C' will always comes before 'D'

Example
INPUT
s1 = "AB"
s2 = "CD"

OUTPUT
ABCD, ACBD, ACDB, CABD, CADB, CDAB

 */

#include <iostream>
#include <string>

using namespace std;


void printInterleavings(string a, int i, string b, int j, string c)
{
 if(i == a.length()  && j == b.length())
  cout << c << endl;
 
 if(i < a.length())
  printInterleavings(a, i+1, b, j, c + a[i]);
 
 if(j < b.length())
  printInterleavings(a, i, b, j+1, c + b[j]);
}


int main ()
{
	string s1 = "AB";
	string s2 = "CD";
	int size = 0;

	printInterleavings(s1,0, s2, 0, "");

	return 0;
}

// Conundrum:

/*
ABCD ACBD ACDB being printed out is fine.
CABD CADB CDAB is printed because after all recursion are done for second IF statement, the original function flows to the third IF-statement
(keep in mind that all parameters are still the same (value of i especially)), which causes the second set of outputs to be produced.
*/
