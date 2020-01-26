/*

Given a number positive number n, find value of f0 + f1 + f2 + …. + fn where fi indicates i’th Fibonacci number. Remember that f0 = 0, f1 = 1, f2 = 1, f3 = 2, f4 = 3, f5 = 5, …

Input  : n = 3
Output : 4
Explanation : 0 + 1 + 1 + 2  = 4

Input  :  n = 4
Output :  7
Explanation : 0 + 1 + 1 + 2 + 3  = 7
Since the answer can be very large, answer modulo 1000000007 should be printed.

Input:
First line contains an integer, the number of test cases 'T' Each test case should contain a positive integer N.

Output:
Print sum of fibonacci numbers.

Constraints:
1 <= T <= 200
1 <= N <= 100000

Example:
Input:
2
6
5
Output:
20
12

*/

#include <iostream>
using namespace std;

int f[100002] = {0};

int fib (int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1 || n == 2) {
        return 1;
    }
    
    return fib(n - 1) + fib(n - 2);
}

int fibMemoization (int n) {
    if (f[n] == 0) {
        f[n] = fib(n);
    }
    return f[n];
}

int main() {
	
	int cases, n;
	
	cin >> cases;
	cin.clear();
	
	for (int i = 0; i < cases; ++i) {
	    cin >> n;
	    int result = 0;
	    
	    
	    for (int i = 0; i <= n; ++i) {
	        result = result + fibMemoization(i) % 1000000007;
	    }
	    
	    cout << result << endl;
	}
	
	return 0;
}
