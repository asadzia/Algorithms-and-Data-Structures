/*
A string is said to be a special palindromic string if either of two conditions is met:

All of the characters are the same, e.g. aaa.
All characters except the middle one are the same, e.g. aadaa.
A special palindromic substring is any substring of a string which meets one of those criteria. Given a string, determine how many special palindromic substrings can be formed from it.

For example, given the string , we have the following special palindromic substrings: .

Function Description

Complete the substrCount function in the editor below. It should return an integer representing the number of special palindromic substrings that can be formed from the given string.

substrCount has the following parameter(s):

n: an integer, the length of string s
s: a string
Input Format

The first line contains an integer, , the length of . 
The second line contains the string .

Constraints

 
Each character of the string is a lowercase alphabet, .

Output Format

Print a single line containing the count of total special palindromic substrings.

Sample Input 0

5
asasd
Sample Output 0

7 
Explanation 0

The special palindromic substrings of  are 

Sample Input 1

7
abcbaba
Sample Output 1

10 
Explanation 1

The special palindromic substrings of  are 

Sample Input 2

4
aaaa
Sample Output 2

10
Explanation 2

The special palindromic substrings of  are 
/*
#include <bits/stdc++.h>

using namespace std;

/*
https://www.geeksforgeeks.org/count-special-palindromes-in-a-string/
*/

// Complete the substrCount function below.
long substrCount(int n, string str) {

    // store count of special Palindromic substring 
    long result = 0; 
  
    // it will store the count of continues same char 
    long sameChar[n] = { 0 }; 
  
    int i = 0; 
  
    // traverse string character from left to right 
    while (i < n) { 
  
        // store same character count 
        int sameCharCount = 1; 
  
        int j = i + 1; 
  
        // count smiler character 
        while (str[i] == str[j] && j < n) 
            sameCharCount++, j++; 
  
        // Case : 1 
        // so total number of substring that we can 
        // generate are : K *( K + 1 ) / 2 
        // here K is sameCharCount 
        result += (sameCharCount * (sameCharCount + 1) / 2); 
  
        // store current same char count in sameChar[] 
        // array 
        sameChar[i] = sameCharCount; 
  
        // increment i 
        i = j; 
    } 
  
    // Case 2: Count all odd length Special Palindromic 
    // substring 
    for (int j = 1; j < n; j++) 
    { 
        // if current character is equal to previous 
        // one then we assign Previous same character 
        // count to current one 
        if (str[j] == str[j - 1]) 
            sameChar[j] = sameChar[j - 1]; 
  
        // case 2: odd length 
        if (j > 0 && j < (n - 1) && 
            (str[j - 1] == str[j + 1] && 
             str[j] != str[j - 1])) 
            result += min(sameChar[j - 1], 
                          sameChar[j + 1]); 
    } 
  
    // subtract all single length substring 
    return result; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
