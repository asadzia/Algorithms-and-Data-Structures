/*
*
* A program to detect a cycle in a directed graph in C++.
*
*
* Created By: Asad zia
*/

#include <iostream>
#include <list>

using namespace std;

class Graph
{
	private:
		/* the total vertices in the graph */
		int Vertices;
		/* the adjacency list used to represent the directed graph */
		list<int> *adj;
		/* a utility function for detecting a cycle */
		bool CycleUtilityFunction (bool* visited, bool* recursiveStack, int v);

	public:
		/* the main function for finding the cycle */
		bool CycleDetection ();
		/* the constructor */
		Graph(int v);
		/* the destructor */
		~Graph();
		/* the function for adding an edge on the graph */
		void addEdge(int src, int dest);
};	
