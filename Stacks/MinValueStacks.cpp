/*

Design and Implement Special Stack Data Structure | Added Space Optimized Version
Question: Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.

Example:

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, which is the minimum 
element in the current stack. 

If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18 which is the minimum 
in the current stack.

*/

#include <iostream>
#include <stack>

using namespace std;

class SpecialStack {

public:
  stack<int> s;
  stack<int> aux;

  void push (int x) {
    s.push(x);

    if (aux.empty()) {
      aux.push(x);
      return;
    }

    if (aux.top() < x) {
      int y = aux.top();
      aux.push(y);
    } else {
      aux.push(x);
    }
  }

  int pop () {
    int y = s.top();
    s.pop();
    aux.pop();
    return y;
  }

  int getMin () {
    return aux.top();
  }
};

int main () {
  SpecialStack s;

  s.push(10);
  s.push(20);
  cout << "Min: " << s.getMin() << endl;
  s.push(5);
  cout << "Min: " << s.getMin() << endl;
  
  return 0;
}
