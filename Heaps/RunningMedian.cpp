/* The running median problem*/

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

#define SIZE 9

using namespace std;

class RunningMedianAlgorithm
{
	private:
		priority_queue<int, vector<int>, greater<int>> Qone;	//min heap for higher portion of numbers
		priority_queue<int> Qtwo;								//max heap for lower portion of numbers

	public:
		static const int length = SIZE;
		int arr[length];
		int size = 0;
		
		void addNumber (int val)
		{
			arr[size++] = val;
		}

		void initHeaps (int num)
		{
				if (Qtwo.size() == 0 || num < Qtwo.top())		
				{
					Qtwo.push(num);	// we need max element here
				}
				else
				{
					Qone.push(num);	// and min element here
				}
		}

		int findMedian ()
		{	
			int median;

			if ((Qone.size() == Qtwo.size()))
			{
				median = (Qone.top() + Qtwo.top()) / 2;
 			}
 			else
 			{
 				if (Qone.size() > Qtwo.size())
 				{
 					median = Qone.top();
 				}
 				else
 				{
 					median = Qtwo.top();
 				}
 			}
 			return median;
		}

		void rebalance()
		{
		    while (Qtwo.size() > Qone.size() + 1)
		    {
    			if (Qone.size() > Qtwo.size() + 1)
    			{	
    				int x = Qone.top();
    				Qone.pop();
    				Qtwo.push(x);
    			}
    			else if (Qtwo.size() > Qone.size() + 1)
    			{
    				int x = Qtwo.top();
    				Qtwo.pop();
    				Qone.push(x);
    			}
		    }
			return;
		}

		void runningMedian ()
		{
			for (int i = 0; i < length; i++)
			{
				initHeaps(arr[i]);
				rebalance();
				int result = findMedian();
				cout << result << " " << Qone.size() << " " << Qtwo.size() << endl;
			}
		}
};

int main (int argc, char ** args)
{
	RunningMedianAlgorithm myObj;
	myObj.addNumber(45);
	myObj.addNumber(76);
	myObj.addNumber(98);
	myObj.addNumber(12);
	myObj.addNumber(5);
	myObj.addNumber(6);
	myObj.addNumber(8);
	myObj.addNumber(1);
	myObj.addNumber(10);

	myObj.runningMedian();

	return 0;
}

