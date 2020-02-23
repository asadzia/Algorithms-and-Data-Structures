#include <iostream>

using namespace std;

// Finding the total number of binary trees possible by N number of nodes

// https://www.geeksforgeeks.org/total-number-of-possible-binary-search-trees-using-catalan-number/

int uniqueBSTs (int n) {

  int sum = 0, n1, n2;

  // base case:
  if (n == 0 || n == 1) {
    return 1;
  }

  for (int i = 0; i < n; ++i) {
    n1 = uniqueBSTs(i);
    n2 = uniqueBSTs(n - i - 1);
    sum += n1 * n2;
  }

  return sum;
}

int main () {
  int nodes = 6;

  cout << uniqueBSTs(nodes) << endl;
  return 0;
}
