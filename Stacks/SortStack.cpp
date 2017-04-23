/*
Description: A program to sort a stack via recursion.
      			 Implemented in C++.
Version:	 1.0
Author:		 Asad Zia
*/

#include <iostream>
#include <stack>

using namespace std;

class Stack 
{
	public:
		int size;
		int length;
		int *stackArr;

	/* Constructor */
	Stack(int);

	void push(int);
	int pop();
	void Sort();
	void Insert(int);
	void deallocate();
};

Stack::Stack (int val)
{
	size = -1;
	length = val;
	stackArr = new int[length];
}

void Stack::push(int item)
{
	if (size + 1 < length)
	{
		size++;
		stackArr[size] = item;
	}
	else
	{
		cout << "Stack Full!" << endl;
	}
}

int Stack::pop()
{
	if (size < 0)
	{
		cout << "Stack Empty!" << endl;
		return -1;
	}
	else
	{
		return stackArr[size--];
	}
}

void Stack::Sort ()
{
	if (size >= 0)
	{
		int val = pop();
		Sort();
		Insert(val);
	}
}
	
void Stack::Insert(int val)
{
	if (size < 0)
	{
		push(val);
		return;
	}

	if (stackArr[size] > val)
	{
		int x = pop();
		Insert(val);
		push(x);
	}
	else
	{
		push(val);
	}
}


void Stack::deallocate()
{
	delete [] stackArr;
}

int main ()
{
	cout << "Begin Execution" << endl;
	Stack myStack(10);
	
	for (int i = 10; i > 0; --i)
	{
		myStack.push(i);
	}
	
	for (int k = 0; k < 10; ++k)
	{
		cout << myStack.stackArr[k] << " ";
	}
	
	cout << endl;
	myStack.Sort();

	for (int j = 0; j < 10; ++j)
	{
		cout << myStack.stackArr[j] << " ";
	}
	cout << endl;

	myStack.deallocate();
	cout << "End Execution" << endl;
	return 0;
}

