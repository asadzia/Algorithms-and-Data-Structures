/*

Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
    
    */
    
    int Solution::titleToNumber(string A) {
    // 65 to 90
    
    int result = 0;
    int totalAlphabets = 26;
    int len = A.length() - 1;
    
    for (int i = A.length() - 1; i >= 0; --i) {
        result += pow(26, len - i) * (A[i] - 'A' + 1);
    }
    
    return result;
}
