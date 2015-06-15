/*
*
* A C++ implmentation of Depth first search on a directed graph.
*
* Created by: Asad zia.
*/

#include "DFS.h"

Graph::Graph (int v)
{
	this->Vertices = v;
	adj = new list<int> [Vertices];
}

Graph::~Graph()
{
	delete [] adj;
}

void Graph::addEdge (int src, int dest)
{
	adj[src].push_back(dest);
}

void Graph::DFSHelper (int x, bool visitedNodes[])
{
	visitedNodes[x] = true;
	cout << x << " ";

	list<int>::iterator i;

	for (i = adj[x].begin(); i != adj[x].end(); i++)
	{
		if (visitedNodes[*i] == false)
		{
			DFSHelper(*i, visitedNodes);
		}
	}
}

void Graph::DFS (int src)
{
	bool *visitedNodes = new bool [Vertices];

	for (int i = 0; i < Vertices; i++)
	{
		visitedNodes[i] = false;
	}

	DFSHelper(src, visitedNodes);
	delete [] visitedNodes;
}

