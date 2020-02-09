
// CPP program to find optimal number of trials 
// for k floors and 2 eggs. 

#include<bits/stdc++.h> 
using namespace std; 
  
int twoEggDrop(int k) 
{ 
   return ceil((-1.0 + sqrt(1 + 8*k))/2.0); 
} 
  
int main() 
{ 
   int k = 100; 
   cout << twoEggDrop(k); 
   return 0;  
} 
