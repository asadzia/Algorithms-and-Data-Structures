/*
*
* A program which calculates the minimum cut of a Graph.
*
* Created By: Asad zia
*/

#include "Graph.h"

Graph::Graph(int v, int e)
{
	this->Vertices = v;
	this->NoOfEdges = e;
	edges = new Edge [e];
}

Graph::~Graph()
{
}

int Graph::Find(Subset subsets[], int x)
{
	/* use path compression */
	if (subsets[x].parent != x)
	{
		subsets[x].parent = Find(subsets, subsets[x].parent);
	}
	return subsets[x].parent;
}

void Graph::Union(Subset subsets[], int x, int y)
{
	int xParent = Find(subsets, x);
	int yParent = Find(subsets, y);

	/* attach the vertex with smaller rank 
	   below the vertex with higher rank */
	if (subsets[xParent].rank > subsets[yParent].rank)
	{
		subsets[yParent].parent = xParent;
	}
	else if (subsets[xParent].rank < subsets[yParent].rank)
	{
		subsets[xParent].parent = yParent;
	}
	/* if the ranks are equal then make one 
	   of the nodes the root and increment its
	   rank */
	else
	{
		subsets[yParent].parent = xParent;
		++subsets[xParent].rank;
	}
}

int Graph::FindMinCut(Graph myGraph)
{
	int V = myGraph.Vertices;
	int E = myGraph.NoOfEdges;
	int minCut = 0;

	/*Create the subset array */
	Subset* subsets = new Subset[V];

	/* initialize the subset array */
	for (int i = 0; i < V; ++i)
	{
		subsets[i].rank = 0;
		subsets[i].parent = i;
	}

	/* The graph is contracted until there
	   are two vertices (V) left */
	while (V > 2)
	{
		/* choose a random Edge */
		int x = rand() % E;

		/* find the subsets of the current edge */
		int subset_one = Find(subsets, myGraph.edges[x].src);
		int subset_two = Find(subsets, myGraph.edges[x].dest);

		/* If the two points of this edge are in the same subset,
		   then there is no point considering this edge */
		if (subset_two == subset_one)
		{
			continue;
		}
		/* otherwise, combine the two points of this edge into one vertex */
		else
		{
			cout << "The edge " << subset_one << "--" << subset_two << " is being contracted!" << endl;
			--V;
			Union(subsets, subset_one, subset_two);
		}
	}

	/* After the loop finishes, we have 2 edges left as per the loop condition */
	/* Hence now we can count the number of edges between the two components */
	for (int j = 0; j < E; ++j)
	{
		int sub_one = Find(subsets, myGraph.edges[j].src);
		int sub_two = Find(subsets, myGraph.edges[j].dest);

		/* in case the parent of each side of the edge is not the same */
		if (sub_one != sub_two)
		{
			++minCut;
		}
	}

	return minCut;
}
