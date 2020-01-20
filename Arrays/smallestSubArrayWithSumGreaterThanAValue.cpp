/*

Smallest subarray with sum greater than a given value
Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.
Examples:
arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}
    x = 280
Output: 4
Minimum length subarray is {100, 1, 0, 200}

arr[] = {1, 2, 4}
    x = 8
Output : Not Possible
Whole array sum is smaller than 8.

*/

// O(n) solution for finding smallest subarray with sum 
// greater than x 
#include <iostream> 
using namespace std; 
  
// Returns length of smallest subarray with sum greater than x. 
// If there is no subarray with given sum, then returns n+1 
int smallestSubWithSum(int arr[], int n, int x) 
{ 
    // Initialize current sum and minimum length
    // min_len is initialized with large value since it will be used for comparisons in the while loop
    int curr_sum = 0, min_len = n+1; 
  
    // Initialize starting and ending indexes 
    int start = 0, end = 0; 
    while (end < n) 
    { 
        // Keep adding array elements while current sum 
        // is smaller than x 
        while (curr_sum <= x && end < n) 
            curr_sum += arr[end++]; 
  
        // If current sum becomes greater than x. 
        while (curr_sum > x && start < n) 
        { 
            // Update minimum length if needed 
            if (end - start < min_len) 
                min_len = end - start; 
  
            // remove starting elements 
            curr_sum -= arr[start++]; 
        } 
    } 
    return min_len; 
} 
  
  
/* Driver program to test above function */
int main() 
{ 
    int arr1[] = {1, 4, 45, 6, 10, 19}; 
    int x = 51; 
    int n1 = sizeof(arr1)/sizeof(arr1[0]); 
    int res1 = smallestSubWithSum(arr1, n1, x); 
    (res1 == n1+1)? cout << "Not possible\n" : 
                    cout << res1 << endl; 
  
    int arr2[] = {1, 10, 5, 2, 7}; 
    int n2 = sizeof(arr2)/sizeof(arr2[0]); 
    x  = 9; 
    int res2 = smallestSubWithSum(arr2, n2, x); 
    (res2 == n2+1)? cout << "Not possible\n" : 
                    cout << res2 << endl; 
  
    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}; 
    int n3 = sizeof(arr3)/sizeof(arr3[0]); 
    x  = 280; 
    int res3 = smallestSubWithSum(arr3, n3, x); 
    (res3 == n3+1)? cout << "Not possible\n" : 
                    cout << res3 << endl; 
  
    return 0; 
} 
