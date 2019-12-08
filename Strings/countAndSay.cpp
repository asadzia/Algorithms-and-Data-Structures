/*
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

*/

string evaluate(string A) {

    string s = A;
    int count = 1;
    
    if (s.length() == 1) {
        return "11";
    }
    
    char c = s[0];
    string result = "";
    
    for (int i = 1; i < s.length(); ++i) {
        
        if (c == s[i]) {
            count++;
        } else {
            result += to_string(count) + string(1, c);
            count = 1;
            c = s[i];
        }
    }
    
    result += to_string(count) + string(1, c);
    
    return result;
}

string Solution::countAndSay(int n) {
    
    if (n == 0) {
        return "";
    } else if (n == 1) {
        return "1";
    }
    
    string prev = "1";
    
    for (int i = 2; i <= n; ++i) {
        prev = evaluate(prev);
    }
    
    return prev;
}
