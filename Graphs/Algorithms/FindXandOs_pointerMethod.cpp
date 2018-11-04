/*
*
* Given n*m fields of O's and X's, where O=white, X=black, for example 

OOOXOOO 
OOXXOXO 
OXOOOXO 

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included). In the example, the answer is 3. 
*
*
*/

#include <iostream>

using namespace std;

/*
* Utility method for exploring and searching for connected components across all surrounding cells (row-wise and column-wise) of the grid
*/
void explore (char** map, int i, int j, int m, int n)
{
	// negative grid values
	if (i < 0 || j < 0)
	{
		return;
	}

	// overflow of grid values
	if (i >= m || j >= n)
	{
		return;
	}

	// If a O is found or & which is sued to replace all X values after they are found.
	if (map[i][j] == 'O' || map[i][j] == '&')
	{
		return;
	}

	map[i][j] = '&';

	/*
	To search for diagonals as well:
    explore(map,i-1,j-1,m,n);
    explore(map,i+1,j+1,m,n);
    explore(map,i-1,j+1,m,n);
    explore(map,i+1,j-1,m,n);
   */

	explore(map, i + 1, j, m, n);
	explore(map, i - 1, j, m, n);
	explore(map, i, j + 1, m, n);
	explore(map, i, j - 1, m, n);
}

/*
The method for searching the connected components using DFS
*/
int dfs (char** map, int m, int n)
{
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'X')
			{
				count++;
				explore(map, i, j, m, n);
			}
		}
	}

	/*
	// To Recover data by replacing &
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '&')
			{
				map[i][j] = 'X';
			}
		}
	}
	*/

	return count;
}

int main()
{
   //OOOXOOO
   //OOXXOX
   //OXOOOXO

	int m = 3;
	int n = 7;

	char ** map;
	map = new char* [m];

	for (int i = 0; i < m; ++i)
	{
		map[i] = new char[n];
	}

  map[0][0] = 'O';
  map[0][1] = 'O';
  map[0][2] = 'O';
  map[0][3] = 'X';
  map[0][4] = 'O';
  map[0][5] = 'O';
  map[0][6] = 'O';

  map[1][0] = 'O';
  map[1][1] = 'O';
  map[1][2] = 'X';
  map[1][3] = 'X';
  map[1][4] = 'O';
  map[1][5] = 'X';
  map[1][6] = 'O';

  map[2][0] = 'O';
  map[2][1] = 'X';
  map[2][2] = 'O';
  map[2][3] = 'O';
  map[2][4] = 'O';
  map[2][5] = 'O';
  map[2][6] = 'O';

    cout << "Number of X's = " << dfs (map, 3, 7) << endl;
}
