/*
*
* A program for finding the number of nodes of the top 5 strongly connected components. 
* The Kosaraju Algorithm is used to detect this.
*
* Created By: Asad zia
*
*/

#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
	public:
		/* the number of Vertices in a graph */
		int Vertices;

		/* the adjacency list used for the graph */
		list<int> *adj;

		/* the constructor */
		Graph (int x);
		
		/* the destructor */
		~Graph();

		/* the function for adding elements to a stack */
		void addVertexToStack(int x, bool visited[], stack<int> &mystack); 

		/* the function for the reverse DFS routine */
		int DFSReverse (int x, bool visited[]);
		
		/* the function for adding an edge to the graph */
		void addEdge(int src, int dest);

		/* the function for reversing the edge-direction of the graph */
		Graph getTranspose();

		/* the function for finding the SCC's of the graph */
		void findSCC();
};
