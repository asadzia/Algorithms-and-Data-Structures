#include <iostream>
#include <vector>

using namespace std;

int binarySearch (vector<int> values, int x, int size)
{
	int result;
	int mid = size / 2;

  if (values[mid] < x)
  {
    result = binarySearch(values, x, mid + size);
  }
  else if (values[mid] > x)
  {
    result = binarySearch(values, x, mid);
  }
  else
  {
    result = values[mid];
  }
	
	return result;
}

int main ()
{
	vector<int> values {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = values.size();
	int x = 2;

	cout << "Found: " << binarySearch(values, x, size) << endl;

	return 0;
}
