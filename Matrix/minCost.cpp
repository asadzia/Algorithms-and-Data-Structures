/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.*/

#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
#include <climits>

using namespace std;

#define M 3
#define N 3

int minCost (int arr[M][N], int m, int n)
{
	if (m < 0 || n < 0)
	{
		return INT_MAX
	}
	if (m == 0 && n == 0)
	{
		return arr[m][n];
	}

	return arr[m][n] + min(minCost(arr, m - 1, n), minCost(arr, m - 1, n - 1), minCost(arr, m, n - 1));
}

int min (int x, int y, int z)
{
	if (x < y && x < z)
	{
		return x;
	}
	else if (z < x && z < y)
	{
		return z;
	}
	else
	{
		return y;
	}
}

int main() 
{ 
   int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
   printf(" %d ", minCost(cost, 2, 2)); 
   return 0; 
} 
