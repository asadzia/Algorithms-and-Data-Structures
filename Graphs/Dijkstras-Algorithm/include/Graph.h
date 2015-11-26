/*
*
* A program for implementing the Dijkistra's algorithm for finding the minimum path
*
*
*
* Created by: Asad Zia
*
*/

#include <iostream>
#include <list>
#include <queue>
#include <climits>

using namespace std;

/*
 * the vertex data structure
 */
typedef struct vertex
{
	int ID;
	int weight;
} Vertex;

/*
 * define a functor for getting a Min Heap according to the weight of the vertex
 */
	struct comparator {
		bool operator() (Vertex i, Vertex j)
		{
			return i.weight > j.weight;
		}
	};

class Graph
{
	private:
		/* the number of vertices in the graph */
		int Vertices;

		/* the adjacency list used for each vertex */
		list<Vertex> *adj;

	public:
		/* the minimum priority queue needed to store the vertices according to their weights */
		priority_queue<Vertex, vector<Vertex>, comparator> minHeap;

		/* the function for adding an edge to the graph */
		void addEdge (int src, int dest, int weight);

		/* the constructor */
		Graph(int v);

		/* the destructor */
		~Graph();

		/* the main dijkistra's algorithm function */
		void dijkstra (int src);

		/* function for printing the result */
		void printShortestPaths(int arr[]);
};
