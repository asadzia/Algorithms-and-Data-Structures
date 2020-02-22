/*
Length of longest increasing circular subarray
Given an array containing n numbers. The problem is to find the length of the longest contiguous subarray in a circular manner such that every element in the subarray is strictly greater than its previous element in the same subarray. Time Complexity should be O(n).

Examples:

Input : arr[] = {2, 3, 4, 5, 1}
Output : 5
{2, 3, 4, 5, 1} is the subarray if we circularly
start from the last element and then take the
first four elements. This will give us an increasing
subarray {1, 2, 3, 4, 5} in a circular manner.

Input : arr[] = {2, 3, 8, 4, 6, 7, 10, 12, 9, 1}
Output : 5
*/

#include <iostream>
#include <climits>

using namespace std;

int findCircularIncreasingSubArray (int arr[], int n) {

  // first find the longest increasing subarray from the beginning
  int max = INT_MIN;
  int count = 1; // because at least 1 number is always increasing :)
  int i;
  int startLengthOfIncreasingSubArray;

  for (i = 1; i < n; ++i) {
    if (arr[i - 1] < arr[i]) {
      count++;
    } else{
      startLengthOfIncreasingSubArray = count;
      break;
    }
  }

  max = count;
  count = 1;

  for (i = i + 1; i < n; ++i) {
    if (arr[i] > arr[i - 1]) {
      count++;
    } else {
      if (max < count) {
        max = count;
      }
      count = 1;
    }
  }

  // after reaching the end of the array, check if last ellement is greater than the first element
  // if yes then add the startLength of the subarray with the last value of count (which is basically 1 is there was no increasing array of number till the last index or it will be some number greater than 1)

  if (arr[n - 1] < arr[0]) {
    count += startLengthOfIncreasingSubArray;
  }

  // Check max again.
  if (max < count) {
    max = count;
  }

  return max;
}

int main () {
  // O(n) complexity

int arr[] = {2, 3, 8, 4, 6, 7, 10, 12, 9, 1};
int n = sizeof(arr)/sizeof(arr[0]); 

cout << findCircularIncreasingSubArray(arr, n) << endl;

return 0;
}
