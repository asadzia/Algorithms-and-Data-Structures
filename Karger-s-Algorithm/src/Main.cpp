/*
*
* A program which calculates the minimum cut of a Graph.
* Since the algorithm is based on the Monte Carlo Algorithm, the minimum cut produced,
* might not be the minimum, hence the program might have to be run again and again.
*
* Created By: Asad zia
*/

#include "Graph.h"
#include <sstream>
#include <fstream>
#include <string>

int main ()
{
	int countedges = 0, vertex, it = 0, x;

	string line;
    ifstream infile("../Data/kargerMinCut.txt");

    if (infile.is_open())
    {
	    while (getline(infile, line))   //read stream line by line
	    {
	 	    stringstream in(line);      //make a stream for the line itself
		    in >> vertex;                 

		    while (in >> x)
		    {
		    	if (x < vertex)
		    	{
		    		continue;
		    	}
		    	++countedges;
		    }
		}
	}
	else
	{
		cout << "Error opening the file" << endl;
	}

	/* initialize the pointer for reading the file from the beginning */
	infile.clear();
	infile.seekg(0, ios::beg);

	/* initialize the Graph */
	Graph myGraph (200, countedges);

	if (infile.is_open())
	{
		for(string Tline; getline(infile, Tline);)  
	    {
	 	    istringstream Tin(Tline); 

		    Tin >> vertex;                 

		    for (int xx; Tin >> xx;)
		    {
		    	if (xx < vertex)
		    	{
		    		continue;
		    	}
		    	myGraph.edges[it].src = vertex;
		    	myGraph.edges[it].dest = xx;
		    	++it;
		    }
		}
	}
	else
	{
		cout << "Error opening the file!" << endl;
	}
	/* to use a different seed for every run */
	srand(time(NULL));

	cout << "The minimum cut for this graph is " << myGraph.FindMinCut(myGraph) << endl;
	
	infile.close();
	return 0;
}
