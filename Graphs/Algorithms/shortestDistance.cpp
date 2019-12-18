/*

Shortest Distance between 2 cells in a matrix:

Given a matrix of N*M order. Find the shortest distance from a source cell to a destination cell, traversing through limited cells only. Also you can move only up, down, left and right. If found output the distance else -1.
s represents ‘source’
d represents ‘destination’
* represents cell you can travel
0 represents cell you can not travel
This problem is meant for single source and destination.

Examples:

Input : {'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '*', '*', '*'}
Output : 6

Input :  {'0', '*', '0', 's'},
         {'*', '0', '*', '*'},
         {'0', '*', '*', '*'},
         {'d', '0', '0', '0'}
Output :  -1

*/


// Define a struct for carrying data of the nodes in the Area
struct node 
{
    int row;
    int col;
    int dist;
    node(int x, int y, int w) : row(x), col(y), dist(w){}
};
 
 // Use BFS to search for the cell marked as 9
int minimumDistance(int numRows, int numColumns, int** area)
{
	// Starting node is always at (0, 0)
    node source(0, 0, 0);
 
    // Visited nodes are tracked here:
    // Nodes which have a 0 value are marked as true so they are not visited again.
    // While others are marked as false
    bool visited[numRows][numColumns];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++)
        {
            if (area[i][j] == 0)
                visited[i][j] = true;
            else
                visited[i][j] = false;
            
        }
    }
 
    // Apply BFS here
    queue<node> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty()) {
        node p = q.front();
        q.pop();
 
        // Node with value 9 found
        if (area[p.row][p.col] == 9)
            return p.dist;
 
        // moving up
        if (p.row - 1 >= 0 &&
            visited[p.row - 1][p.col] == false) {
            q.push(node(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }
 
        // moving down
        if (p.row + 1 < numRows &&
            visited[p.row + 1][p.col] == false) {
            q.push(node(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }
 
        // moving left
        if (p.col - 1 >= 0 &&
            visited[p.row][p.col - 1] == false) {
            q.push(node(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }
 
         // moving right
        if (p.col + 1 < numColumns &&
            visited[p.row][p.col + 1] == false) {
            q.push(node(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}

