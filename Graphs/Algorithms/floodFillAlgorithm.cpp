/*
Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.
Examples:

Input: mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'O', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
Output: mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'X', 'X', 'X'},
                      {'O', 'X', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'O', 'X', 'O'},
                      {'O', 'O', 'X', 'O', 'O', 'O'},
                    };

Input: mat[M][N] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'O', 'O', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };
Input: mat[M][N] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };
*/

#include <iostream>

using namespace std;

#define M 6
#define N 6

void floodFillAlgorithm (char grid[M][N], int m, int n, char newC, char old)
{
	if (m < 0 || n < 0)
	{
		return;
	}

	if (m >= M || n >= N)
	{
		return;
	}

	if (grid[m][n] != newC)
	{
		return;
	}

	grid[m][n] = old;

	floodFillAlgorithm(grid, m + 1, n, newC, old);
	floodFillAlgorithm(grid, m - 1, n, newC, old);
	floodFillAlgorithm(grid, m, n + 1, newC, old);
	floodFillAlgorithm(grid, m, n - 1, newC, old);
}

void replaceSurrounded (char grid [M][N], int m, int n, char old, char newC)
{
	// replace all O's with a -
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == old)
			{
				grid[i][j] = newC;
			}
		}
	}

	// replace all - along the borders and any -'s connected to the border -'s as well since they are not surrounded by X's
	for (int i = 0; i < M; i++)
	{
		if (grid[i][0] == newC)
		{
			floodFillAlgorithm(grid, i, 0, newC, old);
		}
	}

	for (int i = 0; i < M; i++)
	{
		if (grid[i][N - 1] == newC)
		{
			floodFillAlgorithm(grid, i, N - 1, newC, old);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (grid[0][i] == newC)
		{
			floodFillAlgorithm(grid, 0, i, newC, old);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (grid[M - 1][i] == newC)
		{
			floodFillAlgorithm(grid, M - 1, i, newC, old);
		}
	}

	// Replace all '-' with 'X' 
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == newC)
			{
				grid[i][j] = 'X';
			}
		}
	}
}


int main ()
{

    char mat[M][N] =  {{'X', 'O', 'X', 'O', 'X', 'X'}, 
                     {'X', 'O', 'X', 'X', 'O', 'X'}, 
                     {'X', 'X', 'X', 'O', 'X', 'X'}, 
                     {'O', 'X', 'X', 'X', 'X', 'X'}, 
                     {'X', 'X', 'X', 'O', 'X', 'O'}, 
                     {'O', 'O', 'X', 'O', 'O', 'O'}, 
                    };

    replaceSurrounded(mat, M, N, 'O', '-');   
  
    for (int i=0; i<M; i++) 
    { 
      for (int j=0; j<N; j++) 
      {
          cout << mat[i][j] << " "; 
      }
      cout << endl;
    }
    return 0; 
}
