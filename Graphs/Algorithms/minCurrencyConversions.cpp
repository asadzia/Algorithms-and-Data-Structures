// Code for minimum number of conversions needed to convert to the required currency

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct CurrencyNode {
  string source;
  double value;
  // no need to use steps here but added anyways
  int steps;
  CurrencyNode(string src, double val, int s):source(src), value(val), steps(s){};
};

double convert (map<string, map<string, double> > mp, string src, double amount, string dest) {

  if (mp[src].empty()) {
    cout << "Invalid Conversion" << endl;
    return -1;
  }

  queue<CurrencyNode> q;
  q.push(CurrencyNode(src, amount, 0));

  while (!q.empty()) {

    CurrencyNode node = q.front();
    q.pop();

    // if the required currency is found then return the rate
    if (mp[node.source].find(dest) != mp[node.source].end()) {
      return node.value * mp[node.source][dest];
    }

    // else
    for (auto it : mp[node.source]) {
      q.push(CurrencyNode(it.first, it.second * node.value, node.steps + 1));
    }
  }

  cout << "Conversion could not be done" << endl;
  return -1;
}

void insertIntoMap (map<string, map<string, double> > &mp, string src, string dest, double value) {
  mp[src][dest] = value;
}

int main () {
  map<string, map<string, double> > mp;

  insertIntoMap(mp, "EUR", "USD", 1.2);
  insertIntoMap(mp, "USD", "GBP", 0.75);
  insertIntoMap(mp, "GBP", "AUD", 1.7);
  insertIntoMap(mp, "AUD", "YEN", 90);
  insertIntoMap(mp, "GBP", "YEN", 150);
  insertIntoMap(mp, "YEN", "PKR", 0.6);

  cout << convert(mp, "EUR", 100, "PKR") << endl;

  return 0;
}
