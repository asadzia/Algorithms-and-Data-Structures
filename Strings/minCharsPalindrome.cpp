/*

Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.



Input Format

The only argument given is string A.
Output Format

Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".
        
       */
       
 int Solution::solve(string A) {
    
    int x = 0;
    int y = A.length() - 1;
    int end = A.length() - 1;
    
    while (x <= y) {
        if (A[x] == A[y]) {
            x++;
            y--;
        } else {
            x = 0;
            y = --end;
        }
    }
    
    return (A.length() - 1) - end;
    
}
