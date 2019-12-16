/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) */

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> result = {};
    int sum = 0;
    int sz  =A.size();

    sort(A.begin(), A.end());
    
    for (int i = 0; i < sz - 2; ++i) {
        
        // skip duplicates
        if (i > 0) {
            if (A[i] == A[i - 1]) {
                continue;
            }
        }
        
        int ptr1 = i + 1, ptr2 = A.size() - 1;
        
        while (ptr1 < ptr2) {
            
            sum = A[i] + A[ptr1] + A[ptr2];
            
            if (sum == 0) {
                vector<int> N = vector<int>({A[i], A[ptr1], A[ptr2]});
                result.push_back(N);
                ptr1++;
                ptr2--;
                
                // skip duplicates only after sum is found
                while (ptr1 < ptr2) {
                    if (A[ptr1] == A[ptr1 - 1]) {
                        ++ptr1;
                        continue;
                    }
                    break;
                }
                
                 while (ptr2 < A.size() - 1) {
                    if (A[ptr2] == A[ptr2 + 1]) {
                        --ptr2;
                        continue;
                    }
                    break;
                }
            }
            
            if (sum > 0) {
                ptr2--;
            } else if (sum < 0) {
                ptr1++;
            }
        }
    }
    
    return result;
}
