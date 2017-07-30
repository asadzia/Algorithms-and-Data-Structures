#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Intervals
{
	private:
		int start;
		int end;
		vector<Intervals> result;

	public:
	
		Intervals (int x, int y)
		{
			start = x;
			end = y;
		}
		
		struct comp
  	{
		  bool operator() (const Intervals& x, const Intervals& y)
		  {
			return x.start < y.start;
		  } 
	  };

		void sortIntervals(vector<Intervals>& x)
		{
			sort(x.begin(), x.end(), comp());
				for (int i = 0; i < x.size(); i++)
			{
				cout << "Interval: " << "(" << x[i].start << ", " << x[i].end << ")" << endl;
			}
		}
		

		void MergeIntervals (vector<Intervals> &x)
		{
			int start = x[0].start;
			int end = x[0].end;

			Intervals p (start, end);

			result.push_back(p);

			for (int i = 1; i < x.size(); ++i)
			{
			 	if (x[i].start > result[result.size() - 1].end)
			 	{
			 		Intervals w(x[i].start, x[i].end);
			 		result.push_back(w);
			 	} 
			 	else
			 	{
			 		if (x[i].end > result[result.size() - 1].end)
			 		{

			 			result[result.size() - 1].end = x[i].end;
			 		}
			 			
			 	}		 	
			}
		}

		void printIntervals ()
		{
			for (int i = 0; i < result.size(); i++)
			{
				cout << "Interval: " << "(" << result[i].start << ", " << result[i].end << ")" << endl;
			}
		}
};

int main (int argc, char ** args)
{
	vector<Intervals> x;
	Intervals a(1,3);
	Intervals b(2,4);
	Intervals c(5,7);
	Intervals d(6,8);
	
	x.push_back(a);
	x.push_back(b);
	x.push_back(c);
	x.push_back(d);

	a.sortIntervals(x);
  cout << endl;
	a.MergeIntervals(x);
	a.printIntervals();

	return 0;
}
