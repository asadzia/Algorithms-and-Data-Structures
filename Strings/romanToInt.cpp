/*

Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more
details about roman numerals at Roman Numeric System



Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
    
    */
    
    int Solution::romanToInt(string A) {
    
    int result = 0;
    
    for (int i = 0; i < A.length(); ++i) {
        if (A[i] == 'I') {
            result += 1;
        }
        
        if (A[i] == 'V') {
            
            if (A[i - 1] != 'I') {
                result += 5;
            } else {
                result += 3;   
            }
        }
        
        if (A[i] == 'X') {
            if (A[i - 1] != 'I') {
                result += 10;
            } else {
                result += 8;
            }
        }
        
        if (A[i] == 'L') {
            if (A[i - 1] != 'X') {
                result += 50;
            } else {
                result += 30;
            }
        }
        
        if (A[i] == 'C') {
            if (A[i - 1] != 'X') {
                result += 100;
            } else {
                result += 80;
            }
        }
        
        if (A[i] == 'D') {
            if (A[i - 1] != 'C') {
                result += 500;
            } else {
                result += 300;
            }
        }
        
        if (A[i] == 'M') {
            if (A[i - 1] != 'C') {
                result += 1000;
            } else {
                result += 800;
            }
        }
    }
    
    return result;
}
