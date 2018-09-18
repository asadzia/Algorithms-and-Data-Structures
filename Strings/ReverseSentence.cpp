/* Print a sentence in reverse */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	vector<string> vc = {"my", "name", "is", "hello",  "world"};

	int j = vc.size() - 1;
	int i = 0;

	while (i < j)
	{
		string str = vc[i];
		vc[i] = str[j];
		vc[j] = str;
		i++;
		j--;
	}

	for (int i = 0; i < vc.size(); ++i)
	{
		cout << vc[i] << " ";
	}

	return 0;
}
