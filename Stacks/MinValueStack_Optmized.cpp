/*

Design a stack that supports getMin() in O(1) time and O(1) extra space
Question: Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.

Example:

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, 
which is the minimum element in the current stack. 

If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18 
which is the minimum in the current stack.

*/

// Special Stack implementation to get minimum value in O(1) time and O(1) space

#include <iostream>
#include <stack>

using namespace std;

class SpecialStack {

public:
  stack<int> s;
  int minEle;

  void push (int x) {

    if (s.empty()) {
      minEle = x;
      s.push(x);
    }

    if (x > minEle) {
      s.push(x);
    } else {
      int y = 2 * x - minEle;
      s.push(y);
      minEle = x;
    }   
  }

  int pop () {
    if (s.size() == 0) {
      cout << "Nothing to pop" << endl;
      return -1;
    } 

    int y = s.top();
    s.pop();

    if (y < minEle) {
      minEle = 2 * minEle - y;
    }
  }

  int getMin () {
    return minEle;
  }
};

int main () {
  SpecialStack s;

  s.push(3);
  s.push(5);
  s.push(2);
  cout << "Min: " << s.getMin() << endl;
  s.push(1);
  cout << "Min: " << s.getMin() << endl;
  
  return 0;
}
