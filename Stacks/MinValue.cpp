/*
Description: A program which finds the minimum value in a stack in O(1) time complexity.
			 Note: A vector could be used for this implementation to avoid memory allocation for the Stack array since
			 C++ arrays do not support variable length.
			 Implemented in C++.
Version:	 1.0
Author:		 Asad Zia
*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Stack 
{
	public:
		int size;
		int length;
		int *stackArr;
		int *minVal;

	/* Constructor */
	Stack(int);

	void push(int);
	void pop();
	int findMin();
	void deallocate();
};

Stack::Stack (int val)
{
	size = -1;
	length = val;
	stackArr = new int[length];
	minVal = new int[length];
}

void Stack::push(int item)
{
	if (size >= length)
	{
		cout << "Stack Full!" << endl;
	}
	else
	{
		size++;
		stackArr[size] = item;

		if  (size == 0)
		{
			/* First Value */
			minVal[size] = item;
		}
		else
		{
			minVal[size] = item;
			if (minVal[size] > minVal[size - 1])
			{
				int temp = minVal[size];
				minVal[size] = minVal[size - 1];
				minVal[size - 1] = temp;
			}
		}
	}
}

void Stack::pop()
{
	if (size < 0)
	{
		cout << "Stack Empty" << endl;
	}
	else
	{
		cout << "Popped Value " << stackArr[size] << endl;
		size--;
	}
}

int Stack::findMin ()
{
	if (size < 0)
	{
		cout << "Stack Empty!" << endl;
	}
	else
	{
		return minVal[size];
	}
}

void Stack::deallocate()
{
	delete [] stackArr;
	delete [] minVal;
}

int main ()
{
	cout << "Begin Execution" << endl;
	Stack myStack(10);
	
	for (int i = 10; i > 0; --i)
	{
		myStack.push(i);
	}
	cout << myStack.size << endl;
	myStack.pop();
	myStack.pop();

	cout << "Minimum Value in Stack: " << myStack.findMin() << endl;
	myStack.deallocate();
	cout << "End Execution" << endl;
	return 0;
}

