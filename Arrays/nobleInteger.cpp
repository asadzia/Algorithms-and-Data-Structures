/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*/

int solve(vector<int> &A) {
    
    sort(A.begin(), A.end());
    int len = A.size();
    
    vector<int> cur;
    
    for (int i = 0; i < len; ++i) {
        bool flag = false;
        int eles = len - i - 1;
        if (A[i] == eles) {
            
            // handling cases where there are duplicates in the sorted array
            for (int j = i + 1; j < len; ++j) {
                if (A[i + 1] == A[i]) {
                    eles--;
                    flag = true;
                    break;
                } else {
                    break;
                }
            }
            
            if (flag) {
                continue;
            }
            return 1;
        }
    }
    
    return -1;
}
