/*
Given a 2D grid of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form).

The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up and 4 Diagonal directions.

Example:

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "EEE"

Output: pattern found at 0, 2
        pattern found at 0, 10
        pattern found at 2, 2
        pattern found at 2, 12
*/

#include <iostream>
#include <string>

using namespace std;

#define R 3
#define C 14

// Global directional arrays to move in all 8 directions of the grid
int arrR [] = {-1, 0, 1, 1, 1, 0, -1, -1};
int arrC [] = {-1, -1, -1, 0, 1, 1, 1, 0};

bool search (char grid[R][C], int r, int c, string word)
{
	for (int i = 0; i < 8; ++i)
	{
		int rd  = r + arrR[i];
		int cd = c + arrC[i];
		int j;

		for (j = 1; j < word.length(); j++)
		{

			if (rd < 0 || cd < 0 || rd >= R || cd >= C)
			{
				break;
			}

			if (grid[rd][cd] != word[j])
			{
				break;
			}			

			// update cooridinates in one direction
			rd += arrR[i];
			cd += arrC[i];
		}

		if (j == word.length())
		{
			return true;
		}
	}
	return false;
}

void patternSearch (char grid[R][C], int r, int c, string word)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (grid[i][j] == word[0])
			{
				if (search(grid, i, j, word))
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
