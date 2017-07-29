// Implementing a Queue with Two Stacks.

#include <iostream>
#include <vector>

using namespace std;

class Queue{
	private:
		vector<int> first;
		vector<int> second;

	public:
		void push (int val)
		{
			first.push_back(val);
		}

		void pushOne (int val)
		{
			first.push_back(val);
		}

		void pushTwo (int val)
		{
			second.push_back(val);
		}

		int pop()
		{
			int val = first.at(first.size() - 1);
			first.pop_back();
			return val;
		}

		int popOne()
		{
			int val = first.at(first.size() - 1);
			first.pop_back();
			return val;
		}

		int popTwo()
		{
			int val = second.at(second.size() - 1);
			second.pop_back();
			return val;
		}

		void Enqueue (int val)	
		{
			if (first.size() == 0)
			{
				pushOne(val);
			}
			else
			{
				while (first.size() > 0)
				{
					int x = popOne();
					pushTwo(x);
				}

				pushTwo(val);

				while (second.size() > 0)
				{
					int x = popTwo();
					pushOne(x);
				}
			}
		}

		void dequeue ()
		{
			if (first.size() == 0)
			{
				cout << "Queue Empty" << endl;
				return;
			}

			cout << "Dequeued: " << popOne() << endl;
		}
};

int main ()
{
	Queue Q;

	Q.Enqueue(1);
	Q.Enqueue(8);
	Q.Enqueue(2);
	Q.Enqueue(4);
	Q.Enqueue(9358);
	Q.Enqueue(56);
	Q.Enqueue(3);

	Q.dequeue();
	Q.dequeue();

	return 0;
}
