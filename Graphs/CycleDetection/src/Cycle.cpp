/*
*
* A program to detect a cycle in a graph in C++.
*
*
* Created By: Asad zia
*/

#include "Cycle.h"

Graph::Graph (int v)
{
	this->Vertices = v;
	adj = new list<int> [Vertices];
}

Graph::~Graph ()
{
	delete [] adj;
}

bool Graph::CycleUtilityFunction (bool* visited, bool* rec, int v)
{
	if (visited[v] == false)
	{
		visited[v] = true;
		rec[v] = true;

		list<int>::iterator it;

		/* If an unexplored edge leads to a node visited before, then the graph contains a cycle. */
		for (it = adj[v].begin(); it != adj[v].end(); ++it)
		{
			if (visited[*it] == false && CycleUtilityFunction(visited, rec, *it))
			{
				return true;
			}
			else if (rec[*it])
			{
				return true;
			}
		}
	}
	rec[v] = false;
	return false;
}

bool Graph::CycleDetection ()
{
	bool* visited = new bool [Vertices];
	bool* rec = new bool [Vertices];

	for (int i = 0; i < Vertices; i++)
	{
		visited[i] = false;
		rec[i] = false;
	}

	for (int j = 0; j < Vertices; ++j)
	{
		if (CycleUtilityFunction(visited, rec, j))
		{
			return true;
		}
	}
	return false;
}

void Graph::addEdge (int src, int dest)
{
	adj[src].push_back(dest);
}
