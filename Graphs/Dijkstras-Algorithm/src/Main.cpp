/*
*
* A program for implementing the Dijkistra's algorithm for finding the minimum path
*
*
*
* Created by: Asad Zia
*
*/

#include "Graph.h"
#include <fstream>
#include <sstream>

#define NO_OF_VERTICES 200

int main ()
{
	int source, destination, weight;
	char comma;
	string line;

    ifstream infile("../Data/dijkstraData.txt");

    /* initalize the graph */
    Graph myGraph (NO_OF_VERTICES);

    if (infile.is_open())
	{
		while (getline(infile, line))
		{
			stringstream in(line);
			in >> source;
			//cout << source << endl;
			while (in >> destination >> comma >> weight)
			{
				//cout << destination << "  " << comma << "  " << weight << endl; 
				myGraph.addEdge(source - 1, destination - 1, weight);
			}
		}
	}
	else
	{
		cout << "Error opening the file" << endl;
	}

	myGraph.dijkstra(1);
	return 0;
}
