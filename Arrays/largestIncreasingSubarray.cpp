/*

Longest increasing subarray
Given an array containing n numbers. The problem is to find the length of the longest contiguous subarray such that every element in the subarray is strictly greater than its previous element in the same subarray. Time Complexity should be O(n).

Examples:

Input : arr[] = {5, 6, 3, 5, 7, 8, 9, 1, 2}
Output : 5
The subarray is {3, 5, 7, 8, 9}

Input : arr[] = {12, 13, 1, 5, 4, 7, 8, 10, 10, 11}
Output : 4
The subarray is {4, 7, 8, 10}


*/

#include <iostream>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

int findLongestSubArray (vector<int> V) {
    
    int count = 0;
    int max = INT_MIN;
    
    for (int i = 1; i < V.size(); ++i) {
        if (V[i] > V[i - 1]) {
            count++;
            continue;
        } else {
            
            if (count > max) {
                max = count;
            }
            count = 0;
        }
    }
    
    // in case the increasing numbers were found till the end of the array then we need a condition outside of the loop
    if (count > max) {
        max = count;
    }
    
    max++;
    return max;
}

int main() {
	
	int cases;
	vector<int> V;
	stringstream ss;
	
	cin >> cases;
	
	for (int i = 0; i < cases; ++i) {
	    
	    ss.clear();
	    V.clear();
	    
	    string line;
	    int n;
	    int x;
	    
	    cin >> n;
	    cin.ignore();
	    
	    getline(cin, line);

	    ss << line;
	    
	    while (ss >> x) {
	        //cout << " Val: " << x << endl;
	        V.push_back(x);
	    }
	    
	    cout << findLongestSubArray(V) << endl;
	}
	
	return 0;
}
