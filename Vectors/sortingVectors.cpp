#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct comp
{
    bool operator () (const int& x, const int& y) const
    {
        return x < y;
    }
};

int main() {
    int n;
    vector<int> x;
    int c;
    
    cin >> n;
    
    while (n != 0)
    {
        n--;
        cin >> c;
        x.push_back(c);
    }
    
    sort(x.begin(), x.end(), comp());
    
    for (int i = 0; i < x.size(); ++i)
    {
        cout << x[i] << " ";
    }
    
    return 0;
}
