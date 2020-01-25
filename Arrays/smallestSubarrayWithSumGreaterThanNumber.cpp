/*

Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Examples:
A[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two space separated integers N and x. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print the required ouput.

Constraints:
1<=T<=100
1<=N,x<=1000
1<=A[]<=1000

Example:
Input:
2
6 51
1 4 45 6 0 19
5 9
1 10 5 2 7
Output:
3
1

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

void findMinSubarray(vector<int> V, int x) {
    
    int sum = 0, end = 0, s = 0, ans = INT_MAX;
    int start = 0;
    
    for (int i = 0; i < V.size(); ++i) {
        
        sum += V[i];
        if (sum > x) {
            
            while (sum - V[s] > x) {
                sum -= V[s];
                s++;
            }
            
            if (i - s + 1 < ans) {
                end = i;
                start = s;
                ans = end - start + 1;
            }
            continue;
        } 
    }

    cout << ans << endl;
}

int main() {
	
	int cases;
	string word;
	stringstream ss;
	int val;
	
	cin >> cases;
	cin.ignore();
	
	for (int i = 0; i < cases; ++i) {
    	string line, line1;
    	int n, x;
	    ss.clear();
	    
	    getline(cin, line);
	    ss << line;
	    vector<int> V;
	    
	    // array size
	    ss >> n;
	    //cout << "n: " << n << endl;
	    // value of x
	    ss >> x;
	    //cout << "x: " << x << endl;
	    ss.clear();
	    
	    getline(cin, line1);
	    ss << line1;

	    while (ss >> val) {
	        V.push_back(val);
	    }
	    
	    findMinSubarray(V, x);
	}
	
	return 0;
}
