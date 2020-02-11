/*

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included.

Given a number n, the task is to find n’th Ugly number.

Examples:



Input  : n = 7
Output : 8

Input  : n = 10
Output : 12

Input  : n = 15
Output : 24

Input  : n = 150
Output : 5832

*/


#include <iostream>
#include <algorithm>

using namespace std;

long long uglyNumbers (int n) {
    
    // Assume first ugly number is 1
    long long arr[n] = {0};
    arr[0] = 1;
    
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    
    long long nextMultipleOfTwo = arr[i2] * 2;
    long long nextMultipleOfThree = arr[i3] * 3;
    long long nextMultipleOfFive = arr[i5] * 5;
    
    for (int i = 1; i < n; ++i) {
        
        long long minValue = min(nextMultipleOfTwo, min(nextMultipleOfThree,
                            nextMultipleOfFive));
        
        arr[i] = minValue;
        
        if (minValue == nextMultipleOfTwo) {
            i2++;
            nextMultipleOfTwo = arr[i2] * 2;
        }
        
        if (minValue == nextMultipleOfThree) {
            i3++;
            nextMultipleOfThree = arr[i3] * 3;
        }
        
        if (minValue == nextMultipleOfFive) {
            i5++;
            nextMultipleOfFive = arr[i5] * 5;
        }
    }
    
    return arr[n - 1];
}

int main() {
	
	int cases;
	long long n;
	cin >> cases;
	
	for (int i = 0; i < cases; ++i) {
	    
	    cin >> n;
	    
	    cout << uglyNumbers(n) << endl;
	    
	}
	
	return 0;
}
