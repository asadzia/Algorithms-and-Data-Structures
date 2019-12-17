/* Letter combinations of a phone number */

#include <iostream>
#include <string> 
#include <vector>
#include <map>

using namespace std;

void findCombinationsRecursively(string digits, map<char, string> mp, string current, int index, vector<string> result) {

  // termination condition for recursion
  // if both string digits processed
  if (index == digits.length()) {
    cout << current << endl;
    result.push_back(current);
    return;
  }

  // take the numpad string value for the next digit
  string numpadString = mp[digits[index]];

  for (int i = 0; i < numpadString.length(); ++i) {
    findCombinationsRecursively(digits, mp, current + numpadString[i], index + 1, result);
  }
}

vector<string> findCombinations (string digits) {
  vector<string> result;

  map<char, string> mp;
  mp['0'] = "";
  mp['1'] = "";
  mp['2'] = "abc";
  mp['3'] = "def";
  mp['4'] = "ghi";
  mp['5'] = "jkl";
  mp['6'] = "mno";
  mp['7'] = "pqrs";
  mp['8'] = "tuv";
  mp['9'] = "wxyz";

  findCombinationsRecursively(digits, mp, "", 0, result);
  return result;
}

int main () {
  findCombinations("23");
  return 0;
}
