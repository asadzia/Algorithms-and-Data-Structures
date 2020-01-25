/*

Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.
Examples:

Input : str = “001”
Output : 1
Minimum number of flips required = 1
We can flip 1st bit from 0 to 1 

Input : str = “0001010111”
Output : 2
Minimum number of flips required = 2
We can flip 2nd bit from 0 to 1 and 9th 
bit from 1 to 0 to make alternate 
string “0101010101”.
Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of one line. The line contains a string of 0's and 1's.

Output:

Minimum number of characters to be removed to make string alternate.

Constraints:

1 ≤ T ≤ 100
1 ≤ string length ≤ 1000

Example:

Input
2
01010
1111

Output
0
2

*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	
	int n, val;
	stringstream ss;
	cin >> n;
    cin.ignore();   
	
	for (int i = 0; i < n; ++i) {
	    string line;
	    int changes = 0;
	    int changes2 = 0;
	    getline(cin, line);

	    char val1, val2;
	    
	    if (line[0] == '0') {
	        val1 = '0';
	        val2 = '1';
	    } else {
	        val1 = '1';
	        val2 = '0';
	    }

	    for (int i = 1; i < line.length(); ++i) {
	        if (i % 2 == 0 && line[i] != val1) {
	            changes++;
            } else if (i % 2 > 0 && line[i] != val2) {
	            changes++;
	        }
	    }
	    
	    for (int i = 0; i < line.length(); ++i) {
	        if (i % 2 == 0 && line[i] != val2) {
	            changes2++;
            } else if (i % 2 > 0 && line[i] != val1) {
	            changes2++;
	        }
	    }
	    
	    if (changes < changes2) {
	        cout << changes << endl;
	    } else {
	        cout << changes2 << endl;
	    }
	}
	
	return 0;
}
