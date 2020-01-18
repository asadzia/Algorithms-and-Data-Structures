/*
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

*/



vector<int> Solution::findPerm(const string A, int B) {
  
  vector<int> result;
  
  assert(A.length() == B - 1);
  for (int i = 0; i < A.length(); ++i) {
      assert(A[i] == 'I' || A[i] == 'D');
  }
  
  // define the range of values
  int start = 1, end = B, idx = 0;
  
  while (idx < B - 1) {
    if (A[idx] == 'I') {
        result.push_back(start);
        start++;
    }
    else {
        result.push_back(end);
        end--;
    }
    
    idx++;
  }
  
  // final vector position is not filled (N - 1)
  assert(start == end);
  result.push_back(start);
  return result;
}
