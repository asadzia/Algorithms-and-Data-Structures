/*
*
* A program which calculates the minimum cut of a Graph.
*
* Created By: Asad zia
*/

#include <iostream>
#include <cstdlib>
#include <list>
#include <ctime>

using namespace std;

/* Defined to use the union-find rank algorithm in our approach */
typedef struct subset
{
	int parent;
	int rank;
} Subset;

/* the datatype for the edges of the graph */
typedef struct Edge
{
	int src;
	int dest;
} Edge;

class Graph 
{
	private:
		/* the number of vertices in the graph */
		int Vertices;
		/* the number of edges in the graph */
		int NoOfEdges;

	public:
		/* the edge-pairs in the graph */
		Edge* edges;
		/* the constructor */
		Graph(int v, int e);
		/* the destructor */
		~Graph();
		/* the function to find the set of the element x using a path compression technique */
		int Find(Subset subsets[], int x);
		/* the function which does the union of two sets x and y */
		void Union(Subset subsets[], int x, int y);
		/* the function which implements the Kargers algorithm for finding the minimum cut */
		int FindMinCut(Graph myGraph);
};
