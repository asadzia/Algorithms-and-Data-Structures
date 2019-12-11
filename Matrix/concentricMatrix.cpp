/*

Print concentric rectangular pattern in a 2d matrix.
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Example 2:

Input: A = 3.
Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.

*/

vector<vector<int> > Solution::prettyPrint(int n) {
   
    int arraySize = n * 2 - 1; 
    vector<vector<int>> result(arraySize, vector<int>(arraySize, 0));
          
    // Fill the values 
    for(int i = 0; i < arraySize; i++) 
    { 
        for(int j = 0; j < arraySize; j++) 
        { 
            if(abs(i - arraySize / 2) > abs(j - arraySize / 2)) 
                result[i][j] = abs(i - arraySize / 2) + 1; 
            else
                result[i][j] = (abs(j-arraySize / 2) + 1); 
        } 
    } 
    
    return result;
}
