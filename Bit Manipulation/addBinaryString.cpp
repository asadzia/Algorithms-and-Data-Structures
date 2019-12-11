/*

Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

*/

string Solution::addBinary(string A, string B) {

    int i = A.length() - 1, j = B.length() - 1;
    int c = 0, s = 0;
    string result = "";
    
    while (i >= 0 || j >= 0 || c > 0) {
        
        s += c;
        
        // because this string might have already ended due to smaller length
        if (i >= 0) {
            s += A[i] - '0';
        }
        
        // same as above
        if (j >= 0) {
            s += B[j] - '0';
        }
        
        result = (char)('0' + s % 2) + result;
        c = s / 2;
        
        s = 0;
        i--;
        --j;
    }
    
    return result;
}
