/*

A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

Example :
Given encoded message "123",  it could be decoded as "ABC" (1 2 3) or "LC" (12 3) or "AW"(1 23).
So total ways are 3.

*/

#include <iostream> 
#include <cstring> 
using namespace std; 
  
// A Dynamic Programming based function  
// to count decodings 
int countDecodingDP(char *digits, int n) 
{ 
    // A table to store results of subproblems 
    int count[n+1];  
    count[0] = 1; 
    count[1] = 1; 
    //for base condition "01123" should return 0  
    if(digits[0]=='0')   
         return 0; 
    for (int i = 2; i <= n; i++) 
    { 
        count[i] = 0; 
  
        // If the last digit is not 0,  
        // then last digit must add to the number of words 
        if (digits[i-1] > '0') 
            count[i] = count[i-1]; 
  
        // If second last digit is smaller  
        // than 2 and last digit is smaller than 7, 
        // then last two digits form a valid character  
        if (digits[i-2] == '1' ||  
              (digits[i-2] == '2' && digits[i-1] < '7') ) 
            count[i] += count[i-2]; 
    } 
    return count[n]; 
} 
  
// Driver program to test above function 
int main() 
{ 
    char digits[] = "1234"; 
    int n = strlen(digits); 
    cout << "Count is " << countDecodingDP(digits, n); 
    return 0; 
} 
// Modified by Atanu Sen 
