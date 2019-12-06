/*
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
              
              */
              
int Solution::uniquePaths(int A, int B) {
    vector<vector<int>> grid(A, vector<int>(B, 0));

    grid[0][0] = 1;
        
    if (A == 0 && B == 0) {
        return 1;
    }
    
    for(int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
           
            if (j-1 >= 0) {
                grid[i][j] += grid[i][j-1];
            }
            
            if (i-1 >= 0) {
                grid[i][j] += grid[i-1][j];
            }
        }
    }
    
    return grid[A-1][B-1];
}

// Using Combinatronics - Method 2

/*
long long calculateFactorial (int n) {
    long long result = 1;
    
    for (int i = 2; i <= n; ++i) {
        result = result * i;
    }
    cout << result << endl;
    return (long long)result;
}

int Solution::uniquePaths(int A, int B) {
    
    int totalPaths = A + B - 2;
    
    // (A + B - 2)!/((m-1)!(n-1)!)
    int result = (int)(calculateFactorial(totalPaths)/(calculateFactorial(A-1)*calculateFactorial(B-1)));
    return result;
}*/
