/*

Given a N x N Chessboard. The task is to count distinct rectangles from the chessboard. For example, if the input is 8 then the output should be 36.

Examples:

Input: N = 4 
Output: 10

Input: N = 6
Output: 21

Approach:
Suppose N = 8 i.e. 8 x 8 chessboard is given, So different rectangles that can be formed are:



1 x 1, 1 x 2, 1 x 3, 1 x 4, 1 x 5, 1 x 6, 1 x 7, 1 x 8 = 8
      2 x 2, 2 x 3, 2 x 4, 2 x 5, 2 x 6, 2 x 7, 2 x 8 = 7 
            3 x 3, 3 x 4, 3 x 5, 3 x 6, 2 x 7, 3 x 8 = 6 
                  4 x 4, 4 x 5, 4 x 6, 4 x 7, 4 x 8 = 5 
                        5 x 5, 5 x 6, 5 x 7, 5 x 8 = 4
                              6 x 6, 6 x 7, 6 x 8 = 3
                                    7 x 7, 7 x 8 = 2
                                          8 x 8 = 1
So total unique rectangles formed = 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 36 which is the sum of the first 8 natural numbers. So in general, distinct rectangles that can be formed in N x N chessboard is:

Sum of the first N natural numbers = N*(N+1)/2
                                   = 8*(8+1)/2
                                   = 36
                                   
                                   */

#include <bits/stdc++.h>  
using namespace std;  
  
// Function to return the count  
// of distinct rectangles  
int count(int N) 
{ 
    int a = 0; 
    a = (N * (N + 1)) / 2; 
    return a; 
} 
  
// Driver Code 
int main() 
{ 
    int N = 4; 
    cout<<count(N);  
} 
