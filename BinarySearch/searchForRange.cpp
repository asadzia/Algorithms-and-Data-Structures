/*

Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].



Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

 Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
Constraints

1 <= N <= 10^6
1 <= A[i], B <= 10^9
For Example

Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]
    
    */
    
    vector<int> findConsecutive (const vector<int> &A, int s, int e) {
    
    int x = A[s];
    int i;
    vector<int> result;
    result.push_back(s);
    result.push_back(e);
    
    // Quite possible that while divding the array, we get the mid value at the center of a collection of consecutive integers
    if (A[s - 1] == x) {
        for (i = s; i >= 0; --i) {
            if (A[i] == x) {
                continue;
            } else {
                result[0] = i + 1;
                break;
            }
        }
    }
    
    for (i = s + 1; i < A.size(); ++i) {
        if (x == A[i]) {
            continue;
        } else {
            result[1] = i - 1;
            break;
        }
    }

    return result;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    int s = 0;
    int e = A.size() - 1;
    
    while (s <= e) {
        
        int mid = (s + e) / 2;
        
        if (A[mid] == B) {
            return findConsecutive(A, mid, e);
        }
        
        if (A[mid] > B) {
            e = mid - 1;
            continue;
        } else {
            s = mid + 1;
            continue;
        }
    }
}


