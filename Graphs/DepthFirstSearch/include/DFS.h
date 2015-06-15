/*
*
* A C++ implmentation of Depth first search on a directed graph.
*
* Created by: Asad zia.
*/

#include <iostream>
#include <list>

using namespace std;

class Graph
{
	public:
	/* number of vertices in the graph */
	int Vertices;
	/* the adjacency list for each vertex */
	list<int> *adj;
	/* a helper function for implementing DFS */
	void DFSHelper(int x, bool visitedNodes[]);

  /* The constructor */
	Graph(int v);
	/* the destructor */
	~Graph();
	/* the function for adding an edge */
	void addEdge(int src, int dest);
	/* the function for implementing DFS */
	void DFS(int src);
};
