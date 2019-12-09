/* Implementation of strstr */


int Solution::strStr(const string A, const string B) {
    
    int j;
    int i = 0;
    int len = A.length();
    int i_cur = 0;
    
    if (A.length() == B.length() && A.length() == 1 && A[0] == B[0]) {
        return 0;
    }
    
    while (i < len - 1 && (len - i) >= B.length() - 1) {
        i_cur = i;
        
        for (j = 0; j < B.length(); ++j) {
            if (A[i_cur] == B[j]) {
                i_cur++;
            } else {
                break;
            }
        }
        
        if (j == B.length()) {
            return i;
        }
        
        ++i;
        i_cur = 0;
    }
    
    return -1;
}
