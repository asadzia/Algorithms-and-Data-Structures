// C++ program to count total anagram 
// substring of a string 
#include <bits/stdc++.h> 
using namespace std; 
  
// Total number of lowercase characters 
#define MAX_CHAR 26 
  
// Utility method to return integer index 
// of character 'c' 
int toNum(char c) 
{ 
    return (c - 'a'); 
} 
  
// Returns count of total number of anagram 
// substrings of string str 
int countOfAnagramSubstring(string str) 
{ 
    int N = str.length(); 
  
    // To store counts of substrings with given 
    // set of frequencies. 
    
     // create a map with a vector which has frequency of each character in a unique substring
    // basically, each vector key represents a substring in the string with its set of chars
    // the value int denotes the total number of times this particular substring occurs
    // total number of anagrams are then found by (n * (n-1))/2. where n = occurence of substring
    map<vector<int>, int> mp; 
  
    // loop for starting index of substring 
    for (int i=0; i<N; i++) 
    { 
        vector<int> freq(MAX_CHAR, 0); 
  
        // loop for length of substring 
        for (int j=i; j<N; j++) 
        { 
            // update freq array of current 
            // substring 
            freq[toNum(str[j])]++; 
  
            // increase count corresponding 
            // to this freq array 
            mp[freq]++; 
        } 
    } 
  
    // loop over all different freq array and 
    // aggregate substring count 
    int result = 0; 
    for (auto it=mp.begin(); it!=mp.end(); it++) 
    { 
        int freq = it->second; 
        result += ((freq) * (freq-1))/2; 
    } 
    return result; 
} 
  
//  Driver code to test above methods 
int main() 
{ 
    string str = "xyyx"; 
    cout << countOfAnagramSubstring(str) << endl; 
    return 0; 
} 
