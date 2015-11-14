/*
*
* A program for finding the number of nodes of the top 5 strongly connected components. 
* The Kosaraju Algorithm is used to detect this.
*
* Created By: Asad zia
*
*/

#include "Graph.h"

int Count = 0;

Graph::Graph (int x)
{
	this->Vertices = x;
	adj = new list<int> [x];
}

Graph::~Graph ()
{
}

void Graph::addVertexToStack (int x, bool visited[], stack<int> &mystack)
{
	/* node added to stack so mark true */
	visited[x] = true;

	list<int>::iterator it;

	/* for all the vertices adjacent to the current vertex */
	for (it = adj[x].begin(); it != adj[x].end(); ++it)
	{
		if (!visited[*it])
		{
			addVertexToStack(*it, visited, mystack);
		}
	}
	mystack.push(x);
}

int Graph::DFSReverse (int x, bool visited[])
{
	visited[x] = true;
	++Count;

	list<int>::iterator it;

	for (it = adj[x].begin(); it != adj[x].end(); ++it)
	{
		if (!visited[*it])
		{
			Count = DFSReverse(*it, visited);
		}
	}
	return Count;
}

void Graph::addEdge (int src, int dest)
{
	adj[src].push_back(dest);
}

Graph Graph::getTranspose ()
{
	Graph myGraph(Vertices);

	for (int i = 0; i < Vertices; ++i)
	{
		list<int>::iterator it;

		for (it = adj[i].begin(); it != adj[i].end(); ++it)
		{
			myGraph.adj[*it].push_back(i);
		}
	}
	return myGraph;
}

void Graph::findSCC ()
{
	bool *visited = new bool [Vertices];
	stack<int> mystack;
	int counter = 0, flag = 0, printFlag = 0, max;

	int arr[Vertices];

	for (int i = 0; i < Vertices; ++i)
	{
		visited[i] = false;
	}

	/* first DFS */
	for (int j = 0; j < Vertices; ++j)
	{
		if (visited[j] == false)
		{
			addVertexToStack(j, visited, mystack);
		}
	}

	for (int k = 0; k < Vertices; ++k)
	{
		visited[k] = false;
	}

	/* reverse the edges */
	Graph myGraph = getTranspose();

	/* second DFS */
	while (mystack.empty() != true)
	{
		int x = mystack.top();
		mystack.pop();
		Count = 0;

		if (visited[x] == false)
		{
			counter = myGraph.DFSReverse(x, visited);
			arr[flag] = counter;

			++flag;
		}
	}

	/* printing out the top 5 SCC's */
	while (printFlag < 5)
	{
		max = arr[0];
		int max_num = 0; 
		for (int p = 0; p < flag; ++p)
		{
			if (max < arr[p])
			{
				max = arr[p];
				max_num = p;
			}
		}
		cout << max << ", ";

		/* so that this maximum is not read again */
		arr[max_num] = 0;
		printFlag++;
	}
	cout << endl;
}
