/*

Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

*/

string r (string x) {
    int i = 0;
    int j = x.length() - 1;
    
    while (1) {
        if (i < j) {
            char t = x[i];
            x[i] = x[j];
            x[j] = t;
            ++i;
            --j;
        } else {
            break;
        }
    }
    
    return x;
}

int Solution::reverse(int A) {
    
    bool flag = false;
    
    if (A < 0) {
        A *= -1;
        flag = true;
    }
    
    string x = to_string(A);
    //cout << x << endl;
    string y = r(x);
   // cout << y << endl;
    
    int result;
    
   try {
        result = stoi(y);
   } catch (...) {
        return 0;   
   }
    
    if (flag) {
        result *= -1;
    }
    return result;
}
