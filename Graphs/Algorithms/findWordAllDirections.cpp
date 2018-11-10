/*
Given a 2D grid of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form).

The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up and 4 Diagonal directions.

NOTE: In this case, the word can be found in ANY direction in DFS-manner.

Example:

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "GEEKS"

Output: Pattern found at (0, 0).
		Pattern found at (0, 8).
		Pattern found at (1, 0).
		Pattern found at (1, 9).

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "EEE"

Output: Pattern found at (0, 1).
		Pattern found at (0, 2).
		Pattern found at (0, 9).
		Pattern found at (0, 10).
		Pattern found at (1, 1).
		Pattern found at (1, 2).
		Pattern found at (1, 10).
		Pattern found at (1, 11).
		Pattern found at (2, 2).
		Pattern found at (2, 12).
*/

#include <iostream>
#include <string>

using namespace std;

#define R 3
#define C 14

bool search (char grid[R][C], int r, int c, string word, int idx)
{
	if (r < 0 || c < 0 || r >= R || c >= C)
	{
		return false;
	}

	if (grid[r][c] != word[idx])
	{
		return false;
	}

	if (idx == word.length())
	{
		return true;
	}

	idx++;

	search(grid, r + 1, c, word, idx);
	search(grid, r - 1, c, word, idx);
	search(grid, r, c + 1, word, idx);
	search(grid, r, c - 1, word, idx);

	search(grid, r - 1, c + 1, word, idx);
	search(grid, r - 1, c - 1, word, idx);
	search(grid, r + 1, c + 1, word, idx);
	search(grid, r + 1, c - 1, word, idx);
}

void patternSearch (char grid[R][C], int r, int c, string word)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (grid[i][j] == word[0])
			{
				if (search(grid, i, j, word, 0))
				{
					cout << "Pattern found at (" << i << ", " << j << ")." << endl; 
				}
			}
		}
	}
}

int main()
{
    char grid[R][C] = {"GEEKSFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IDEQAPRACTICE"
                      };
 
    patternSearch(grid, R, C, "GEEKS");
    cout << endl; 
    patternSearch(grid, R, C, "EEE");
    return 0;
}
