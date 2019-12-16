/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int bestSum = 100000000;
    
    for (int i = 0; i < A.size() - 2; ++i) {
        // fix the minimum value and move it accordingly after subsequent comparisons
        
        int ptr1 = i + 1, ptr2 = A.size() - 1;
        
        while (ptr1 < ptr2) {
            
            int sum = A[ptr1] + A[ptr2] + A[i];
            
            if (abs(B - sum) < abs(bestSum - B)) {
                bestSum = sum;
            }
            
            if (sum < B) {
                ++ptr1;
            } else {
                --ptr2;
            }
        }
    }
    
    return bestSum;
}
