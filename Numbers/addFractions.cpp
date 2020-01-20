/*

Add two fraction a/b and c/d and print answer in simplest form.

Examples :

Input:  1/2 + 3/2
Output: 2/1

Input:  1/3 + 3/9
Output: 2/3

Input:  1/5 + 3/15
Output: 2/5

*/

// C++ program to add 2 fractions 
#include<bits/stdc++.h> 
using namespace std; 
  
// Function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
  
// Function to convert the obtained fraction 
// into it's simplest form 
void lowest(int &den3, int &num3) 
{ 
    // Finding gcd of both terms 
    int common_factor = gcd(num3,den3); 
  
    // Converting both terms into simpler  
    // terms by dividing them by common factor  
    den3 = den3/common_factor; 
    num3 = num3/common_factor; 
} 
  
//Function to add two fractions 
void addFraction(int num1, int den1, int num2,  
                 int den2, int &num3, int &den3) 
{ 
    // Finding gcd of den1 and den2 
    den3 = gcd(den1,den2); 
  
    // Denominator of final fraction obtained 
    // finding LCM of den1 and den2 
    // LCM * GCD = a * b  
    den3 = (den1*den2) / den3; 
  
    // Changing the fractions to have same denominator 
    // Numerator of the final fraction obtained 
    num3 = (num1)*(den3/den1) + (num2)*(den3/den2); 
  
    // Calling function to convert final fraction 
    // into it's simplest form 
    lowest(den3,num3); 
} 
  
// Driver program 
int main() 
{ 
    int num1=1, den1=500, num2=2, den2=1500, den3, num3; 
    addFraction(num1, den1, num2, den2, num3, den3); 
    printf("%d/%d + %d/%d is equal to %d/%d\n", num1, den1, 
                                   num2, den2, num3, den3); 
    return 0; 
} 
