/*
Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:

    1. If there is a tie, then compare with segment's length and return segment which has maximum length.
    2. If there is still a tie, then return the segment with minimum starting index.


Input Format:

The first and the only argument of input contains an integer array A, of length N.
Output Format:

Return an array of integers, that is a subarray of A that satisfies the given conditions.
Constraints:

1 <= N <= 1e5
1 <= A[i] <= 1e5
Examples:

Input 1:
    A = [1, 2, 5, -7, 2, 3]

Output 1:
    [1, 2, 5]

Explanation 1:
    The two sub-arrays are [1, 2, 5] [2, 3].
    The answer is [1, 2, 5] as its sum is larger than [2, 3].

Input 2:
    A = [10, -1, 2, 3, -4, 100]
    
Output 2:
    [100]

Explanation 2:
    The three sub-arrays are [10], [2, 3], [100].
    The answer is [100] as its sum is larger than the other two.
    */
    
    vector<int> maxset(vector<int> &A) {
    long long sum = 0;
    int len = 0;
    int end_idx;
    long long max_sum = 0;
    int min_idx;
    int max_len = 0;
    int end = 0;
    
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] >= 0) { // include 0 to handle cases like [0, 0, -1, 0] where the answer is [0, 0]
            sum += A[i];
            len++;
            
            if (sum > max_sum) {
                max_len = len;
                max_sum = sum;
                end_idx = i;
                min_idx = end_idx + 1 - len;
            }
            
            if (sum == max_sum && max_len < len) {
                max_len = len;
                end_idx = i;
                min_idx = end_idx + 1 - len;
            }
            
            continue;
        }
        

        len = 0;
        sum = 0;
    }
    
    vector<int> result;
    
    for (int j = min_idx; j <= end_idx; ++j) {
        result.push_back(A[j]);
    }
    
    return result;
}

