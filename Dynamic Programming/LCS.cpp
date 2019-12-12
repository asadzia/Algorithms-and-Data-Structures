// LCS Problem

#include <iostream>
#include <string> 
#include <vector>
#include <map>

using namespace std;

int max (int x, int y) {
  if (x > y) {
    return x;
  }  

  return y;
}

int findLcs (string X, string Y, int m, int n) {

  
      if (m == 0 || n == 0) {
        return 0;
      } else if (X[m - 1] == Y[n - 1]) {
        return findLcs(X, Y, m-1, n-1) + 1;
      } else {
        return max(findLcs(X, Y, m, n - 1), findLcs(X, Y, m - 1, n));
      }
}

int main () {
  cout << findLcs("AXGWF", "AFOGF", 5, 5);
  return 0;
}
