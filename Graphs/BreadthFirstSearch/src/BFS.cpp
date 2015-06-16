/*
*
* A C++ program to implement breadth first search for a directed graph.
*
* Created By: Asad Zia.
*
*/

#include "BFS.h"

Graph::Graph (int v)
{
	this->Vertices = v;
	adj = new list<int> [Vertices];
}

Graph::~Graph ()
{
	delete [] adj;
}

void Graph::addEdge (int src, int dest)
{
	adj[src].push_back(dest);
}

void Graph::BFS (int v)
{
	bool *visitedNodes = new bool [this->Vertices];

	/* initially all nodes are unvisited, hence marked false */
	for (int i = 0; i < Vertices; ++i)
	{
		visitedNodes[i] = false;
	}

	/* the starting node is marked true */
	visitedNodes[v] = true;

	/* add the starting node to a list which keeps track of all the connected vertices */
	list <int> buffer;
	buffer.push_back(v);

	list <int>::iterator it;

	while (buffer.empty() != true)
	{
		/* remove the vertex from the list and print it */
		v = buffer.front();
		cout << v << " ";
		buffer.pop_front();

		/* check the adjacency list of the removed vertex */
		for (it = adj[v].begin(); it != adj[v].end(); ++it)
		{
			if (visitedNodes[*it] == false)
			{
				visitedNodes[*it] = true;
				buffer.push_back(*it);
			}
		}
	}
}
