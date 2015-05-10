/*
*
* A program for finding the greatest common divisor for 2 numbers in C++.
*
* Created by: Asad Zia
*/


#include <iostream>

using namespace std;

/*
* The function for computing the G.C.D
*/
int gcd (int x, int y) {

        do{
            int t = x%y;
            x = y;
            y = t;
        }
        while(y != 0);
        return x;
}

/*
* The main function
*/
int main () {
  int a, b;
  cout << "Enter two numbers:\n" << endl;
  cin>> a;
  cin>> b;

  cout << "The greatest common divisor is " << gcd(a, b) << endl;

  return 0;
}

