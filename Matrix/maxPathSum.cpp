/*
Maximum path sum in matrix
Given a matrix of N * M. Find the maximum path sum in matrix. The maximum path is sum of all elements from first row to last row where you are allowed to move only down or diagonally to left or right. You can start from any element in first row.

Examples:

Input : mat[][] = 10 10  2  0 20  4
                   1  0  0 30  2  5
                   0 10  4  0  2  0
                   1  0  2 20  0  4
Output : 74
The maximum sum path is 20-30-4-20.

Input : mat[][] = 1 2 3
                  9 8 7
                  4 5 6
Output : 17
The maximum sum path is 3-8-6.
*/

// CPP prorgam for finding max path in matrix 
// This method ensures that every row gets updated with the sum in each row iteration.
#include <bits/stdc++.h> 
#define N 4 
#define M 6 
using namespace std; 
  
// To calculate max path in matrix 
int findMaxPath(int mat[N][M]) 
{ 
  
    for (int i = 1; i < N; i++) { 
        for (int j = 0; j < M; j++) { 
  
            // When all paths are possible 
            if (j > 0 && j < M - 1) 
                mat[i][j] += max(mat[i - 1][j], 
                             max(mat[i - 1][j - 1],  
                             mat[i - 1][j + 1])); 
  
            // When diagonal right is not possible 
            else if (j > 0) 
                mat[i][j] += max(mat[i - 1][j], 
                            mat[i - 1][j - 1]); 
  
            // When diagonal left is not possible 
            else if (j < M - 1) 
                mat[i][j] += max(mat[i - 1][j], 
                            mat[i - 1][j + 1]); 
  
            // Store max path sum 
        } 
    } 
    int res = 0; 
    for (int j = 0; j < M; j++)  
        res = max(mat[N-1][j], res); 
    return res; 
} 
  
// Driver program to check findMaxPath 
int main() 
{ 
      
    int mat1[N][M] = { { 10, 10, 2, 0, 20, 4 }, 
                    { 1, 0, 0, 30, 2, 5 }, 
                    { 0, 10, 4, 0, 2, 0 }, 
                    { 1, 0, 2, 20, 0, 4 } }; 
              
    cout << findMaxPath(mat1) << endl; 
    return 0; 
} 




/*
//Intuitive but slightly inefficient approach!

#include <iostream>

using namespace std;

#define X 4
#define Y 6

int max (int x, int y) {
  if (x > y) {
    return x;
  }
  return y;
} 

int findMaxPath (int mat[X][Y]) {

  int result = 0;

  for (int i = 0; i < X - 1; ++i) {
    for (int j = 0; j < Y; ++j) {

      // cant get diagnol left
      if (j == 0) {
        mat[i][j] += max(mat[i + 1][j], mat[i + 1][j + 1]);
        // Can't have the below code here because we are updating the beow row midway while making calculations for current row. So this is done once the entire set of calculations is done for the current row and then the overall update is made in the next for loop with the k-index
        //mat[i + 1][j] = mat[i][j];
      }

      // cant get right diagnol
      else if (j == Y - 1) {
        mat[i][j] += max(mat[i + 1][j], mat[i + 1][j - 1]);
        // Can't have the below code here because we are updating the beow row midway while making calculations for current row. So this is done once the entire set of calculations is done for the current row and then the overall update is made in the next for loop with the k-index
        //mat[i + 1][j] = mat[i][j];
      }

      // all positions available
      else if (j > 0 && j < Y - 1) {
        mat[i][j] += max(mat[i + 1][j], max(mat[i + 1][j + 1], mat[i + 1][j - 1]));
        // Can't have the below code here because we are updating the beow row midway while making calculations for current row. So this is done once the entire set of calculations is done for the current row and then the overall update is made in the next for loop with the k-index
        //mat[i + 1][j] = mat[i][j];
      }
    }

    for (int k = 0; k < Y; k++) {
      mat[i + 1][k] = mat[i][k];
    }

  } // end loops

  for (int i = 0; i < Y; ++i) {
    result = max(mat[X - 1][i], result);
  }

  return result;
}

int main() {
   int mat1[X][Y] = { { 10, 10, 2, 0, 20, 4 }, 
                    { 1, 0, 0, 30, 2, 5 }, 
                    { 0, 10, 4, 0, 2, 0 }, 
                    { 1, 0, 2, 20, 0, 4 } }; 
              
    cout << findMaxPath(mat1) << endl; 
    return 0;
}

*/
