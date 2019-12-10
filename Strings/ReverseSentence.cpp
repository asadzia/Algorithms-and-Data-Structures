/* 
Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.



Input Format

The only argument given is string A.
Output Format

Return the string A after reversing the string word by word.
For Example

Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"
    
*/

string Solution::solve(string A) {
    
    stringstream ss;
    ss << A;
    string word;
    vector<string> v;
    
    while (getline(ss, word, ' ')) {
        v.push_back(word);
    }
    
    int i = 0, j = v.size() - 1;
    
    while (true) {
        if (i < j) {
            string temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            ++i;
            --j;
        } else {
            break;
        }
    }
    
    
    string result = "";
    
    for (int k = 0; k < v.size(); ++k) {
        result = result + v[k] + " ";
    }
    
    return result.substr(0, result.length() - 1);
}


/*
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
*/
