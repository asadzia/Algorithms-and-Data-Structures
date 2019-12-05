/*
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
        */
        
        void Solution::setZeroes(vector<vector<int> > &A) {
    
    // https://www.geeksforgeeks.org/a-boolean-matrix-question/
    
    bool rowFlag = false;
    bool colFlag = false;
    
    int colLen = A[0].size();
    
    for (int i = 0; i < A.size(); ++i) {
        // Mark the 0's in the first row and column which act as auxillary arrays
        for (int j = 0; j < A[i].size(); ++j) {
            if (i == 0 && A[i][j] == 0) {
                rowFlag = true;
            }
            
            if (j == 0 && A[i][j] == 0) {
                colFlag = true;
            }
            
            if (A[i][j] == 0) {
                A[0][j] = 0;
                A[i][0] = 0;
            } 
        }
    }
        
    // Mark the 0's in the inner matrix
    for (int i = 1; i < A.size(); ++i) {
        for (int j = 1; j < A[i].size(); ++j) {
            if (A[0][j] == 0) {
                A[i][j] = 0;
            }
            
            if (A[i][0] == 0) {
                A[i][j] = 0;
            }
        }
    }
    
    // mark the 0's in the first row
    for (int i = 0; i < colLen; ++i) {
        if (rowFlag) {
            A[0][i] = 0;
        }
    }
    
    // mark the 0's in the first column
    for (int j = 0; j < A.size(); ++j) {
        if (colFlag) {
            A[j][0] = 0;
        }
    }
}
