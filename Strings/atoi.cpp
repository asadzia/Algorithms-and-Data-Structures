/*

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
*/

int Solution::atoi(const string A) {
    
    int result = 0;
    char c = '0';
    bool garbage = false;
    bool negative = false;
    int prev = 0;
    
    if ((A[0] < '0' || A[0] > '9') && A[0] != '-' && A[0] != '+') {
        return 0;
    } else if (A[0] == '-') {
        negative = true;
    } else if (A[0] >= '0' && A[0] <= '9') {
        result += A[0] - c;
    }
    
    for (int i = 1; i < A.size(); ++i) {

        if (A[i] < '0' || A[i] > '9') {
            break;
        }
        
        prev = result;
        int x = A[i] - c;
        result = result * 10 + x;
        
        // since the last digit of INT_MAX is 7
        if (prev != 0 && INT_MAX/10 < prev || (prev == INT_MAX/10 && x > 7)) {
            if (negative) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }
    }
    
    if (negative) {
        result *= -1;
    }
    return result;
}
