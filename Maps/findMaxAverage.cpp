/*

given array of students and their marks in different subjects. Find maximum average of the student.
{“James”, “70”}, {“Fernando”, “90”}, {“Nick”, “60”}, {“James”, “10”}
Ans should be name = Fernando, max avg =90

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int findMaxAverage (vector<vector <string> > V) {

  map<string, int> mp;

  for (int i = 0; i < V.size(); ++i) {

    // find average
    if (mp[V[i][0]] > 0) {
      mp[V[i][0]] = (mp[V[i][0]] + stoi(V[i][1]))/2;
    } else {
       mp[V[i][0]] = stoi(V[i][1]);
    }
  }

  map<string, int>::iterator it;
  int max = 0;
  string name;

  for (it = mp.begin(); it != mp.end(); it++) {
    if (max < it->second) {
      max = it->second;
      name = it->first;
    }
  } 

  cout << max << endl;
  cout << name << endl;

  return max;  
}

int main () {
  
  vector<vector<string > > V;
  vector<string> A {"Ben", "20"};
  vector<string> B {"Mike", "50"};
  vector<string> C {"Steve", "70"};
  vector<string> D {"Mike", "10"};
  vector<string> E {"Steve", "10"};
  vector<string> F {"Ben", "100"};

  V.push_back(A);
  V.push_back(B);
  V.push_back(C);
  V.push_back(D);
  V.push_back(E);
  V.push_back(F);

  findMaxAverage(V);  
  return 0;
}
