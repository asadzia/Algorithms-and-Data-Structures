#include <iostream>
#include <string>
#include <utility>
#include <map>

using namespace std;

void addToMap (map<string, int>& x, string word)  // Note: The Reference is important here. Otherwise the map data is statically stored and would require the addToMap function to have a return value as a map.
{
	map<string,int>::iterator it;
	it = x.find(word);
    
	if (it != x.end())
	{
		cout << "Found! Increment Acount" << endl;
		it->second++;
	}
	else
	{
		x.insert(pair<string, int>(word, 1));
		cout << "Insert new value " << word <<  endl;
	}
}

int main (int argc, char** args)
{
	map<string,int> myMap;
	myMap = addToMap(myMap, "asad");
	myMap = addToMap(myMap, "asad");
	myMap = addToMap(myMap, "asad");
	myMap = addToMap(myMap, "asad");
	myMap = addToMap(myMap, "lala");
	myMap = addToMap(myMap, "lala");
	myMap = addToMap(myMap, "lala");

	

	cout << myMap.find("asad")->second << endl;

	return 0;
}
