/*

Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.
This is a famous Google interview question, also being asked by many other companies now a days.

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" 
or "i like sam sung".

*/

#include <iostream>
#include <string>

using namespace std;

bool checkDictionary (string str, string dictionary [], int n) {

  for (int i = 0; i < n; ++i) {
    if (str == dictionary[i]) {
      return true;
    }
  }

  return false;
}

bool wordBreak (string str, string dictionary [], int n) {

  // base case
  if (str.length() == 0) {
    return true;
  }

  for (int i = 1; i <= str.length(); ++i) {

    if (checkDictionary(str.substr(0, i), dictionary, n)) {
      if (wordBreak(str.substr(i, str.length() - i), dictionary, n)) {
        return true;
      }
    }
  }

  return false;
}

int main () {

    string dictionary[] = {"mobile","samsung","sam","sung", 
                            "man","mango","icecream","and", 
                             "go","i","like","ice","cream"}; 
    
    int n = sizeof(dictionary)/sizeof(dictionary[0]);

    wordBreak("ilikesamsung", dictionary, n)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("iiiiiiii", dictionary, n)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("", dictionary, n)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("ilikelikeimangoiii", dictionary, n)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("samsungandmango", dictionary, n)? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("samsungandmangok", dictionary, n)? cout <<"Yes\n": cout << "No\n"; 
    return 0; 

  return 0;
}
