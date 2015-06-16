/*
*
* A C++ program to implement breadth first search for a directed graph.
*
* Created By: Asad Zia.
*
*/

#include <iostream>
#include <list>

using namespace std;

class Graph 
{
	private:
		/* the number of vertices in the graph */
		int Vertices;
		/* the adjaceny list for each vertex on the graph */
		list <int> *adj;

	public:
		/* the constructor */
		Graph (int v);
		/* the destructor */
		~Graph();
		/* the function for adding an edge on the graph */
		void addEdge(int src, int dest);
		/* the function for implmenting the breadth first search */
		void BFS (int v);
};
