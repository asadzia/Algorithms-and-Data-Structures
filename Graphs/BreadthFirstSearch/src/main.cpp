/*
*
* A C++ program to implement breadth first search for a directed graph.
*
* Created By: Asad Zia.
*
*/

#include "BFS.h"

/*
* The main function
*/
int main ()
{
	Graph myGraph(4);
	myGraph.addEdge(0, 1);
	myGraph.addEdge(0, 2);
	myGraph.addEdge(1, 2);
	myGraph.addEdge(2, 0);
	myGraph.addEdge(2, 3);
	myGraph.addEdge(3, 3);

	cout << "The breadth first travesrsal for this graph is shown below:" << endl;
	myGraph.BFS(2);

	return 0;
}
