/*
*
* An implementation of Depth first algorithm for a directed graph in C++.
*
*
* Created by: Asad Zia
*/

#include <iostream>
#include <list>

using namespace std;

/*
* A class for the Graph used for depth-first search
*/
class Graph
{
	int Vertices;
	list<int> *AdjacencyList;
	void DFShelper	(int v, bool visitedNodes[]);

	public:
		Graph(int v);
		void addEdge(int src, int dest);
		void DFS (int v);
};

/*
* The constructor for the graph
*/
Graph::Graph (int v)
{
	this->Vertices = v;
	AdjacencyList = new list<int> [v];
}

/*
* A method for adding the edges to our graph
*/
void Graph::addEdge (int src, int dest)
{
	AdjacencyList[src].push_back(dest);
}

/*
* A helper method for recursively checking each node of the graph 
* The method also prints out the visited nodes as a result of DFS
*/
void Graph::DFShelper (int v, bool visitedNodes[])
{
	/* the current node being visited is marked as true */
	visitedNodes[v] = true; 
	cout << v << " ";

	list<int>::iterator it;

	for (it = AdjacencyList[v].begin(); it != AdjacencyList[v].end(); it++)
	{
		if (visitedNodes[*it] == false)
		{
			DFShelper(*it, visitedNodes);
		}
	}
}

/*
* The general DFS algorithm used on our graph.
*/
void Graph::DFS (int v)
{
	bool *visitedNodes = new bool [Vertices];

	/* initially all nodes are marked as false to show they have not been visited */
	for (int i = 0; i < Vertices; i++)
	{
		visitedNodes[i] = false;
	}

	DFShelper(v, visitedNodes);
}

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
 
    cout << "The depth first traversal from vertex 2 is shown below: \n";
    myGraph.DFS(2);
 
    return 0;
}
