/*
*
* A program for finding the number of nodes of the top 5 strongly connected components. 
* The Kosaraju Algorithm is used to detect this.
*
* Created By: Asad zia
*
*/

#include "Graph.h"
#include <fstream>
#include <sstream>

#define VERTICES 875714

int main ()
{
	string line;
	int source, destination;

	ifstream infile("../Data/SCC.txt");

	/* initialize the Graph */
	Graph myGraph (VERTICES);

	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			stringstream in(line);
			in >> source;
			in >> destination;

			myGraph.addEdge(source - 1, destination - 1);
		}
	}
	else
	{
		cout << "Error opening the file" << endl;
	}

	cout << "The top five SCC's are: " << endl;
	myGraph.findSCC();

	infile.close();
	return 0;
}
