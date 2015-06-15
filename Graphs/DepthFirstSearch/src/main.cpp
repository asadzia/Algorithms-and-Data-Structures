/*
*
* A C++ implmentation of Depth first search on a directed graph.
*
* Created by: Asad zia.
*/

#include "DFS.h"

int main ()
{
	Graph myGraph(4);
	myGraph.addEdge(0, 1);
	myGraph.addEdge(0, 2);
	myGraph.addEdge(1, 2);
	myGraph.addEdge(2, 0);
	myGraph.addEdge(2, 3);
	myGraph.addEdge(3, 3);

	cout << "The depth first travesrsal for this graph is shown below:" << endl;
	myGraph.DFS(2);

	return 0;
}
