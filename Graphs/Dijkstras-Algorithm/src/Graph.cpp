/*
*
* A program for implementing the Dijkistra's algorithm for finding the minimum path
*
*
*
* Created by: Asad Zia
*
*/

#include "Graph.h"

Graph::Graph(int v)
{
	this->Vertices = v;
	adj = new list<Vertex> [v];
}

Graph::~Graph ()
{
}

void Graph::addEdge (int src, int dest, int weight)
{
	Vertex x;
	x.ID = dest;
	x.weight = weight;
	adj[src].push_back(x);
}

void Graph::printShortestPaths (int arr[])
{
	cout << "The Shortest paths are as follows: " << endl;
	cout << "Vertex      Distance from Source" << endl;
	for (int i = 0; i < this->Vertices; ++i)
	{
		cout << i + 1 << "             " << arr[i] << endl;
	}
}

void Graph::dijkstra (int src)
{
	int dist[Vertices];

	for (int j = 0; j < this->Vertices; ++j)
	{
		dist[j] = INT_MAX;
	}

	Vertex x;
	x.ID = src - 1;
	x.weight = 0;
	minHeap.push(x);

	dist[src - 1] = 0;

	while (!minHeap.empty())
	{
		Vertex y = minHeap.top();
		
		/* cout << "The top " << minHeap.top().weight << "  " << minHeap.top().ID << endl; */
		/* cout << "Size: " << minHeap.size() << endl; */
		minHeap.pop();

		list<Vertex>::iterator it;

		for (it = adj[y.ID].begin(); it != adj[y.ID].end(); ++it)
		{
			int distance = y.weight + it->weight;
			if (dist[it->ID] == INT_MAX)
			{
				dist[it->ID] = distance;
				it->weight = distance;
				minHeap.push(*it);
			}
			if (dist[it->ID] > distance)
			{
				dist[it->ID] = distance;

				/* we need to update the distance values in the
				   minHeap as well, otherwise we will get 
				   erroneous values for the resultant weight.
				   Since we are using the STL prioeirty-queue,
				   we do not have the option of updating the queue
				   content. Therefore, we will just add the node
				   with the same ID but with the updated distance 
				   value. This will result in multiple entries
				   of nodes with similar ID's but the one with a 
				   lower distacne value will always be considered 
				   first, so out program will in this case.
				   To avoid having multiple entries in the minHeap,
				   we can implement our own minHeap which allows
				   the removal/update of the nodes in the minHaap
				*/
				it->weight = distance;
				minHeap.push(*it);
			}
		}
	}

	printShortestPaths(dist);
}

/*

#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <functional>
#include <climits>

using namespace std;

struct Vertex {
  int ID;
  int weight;
  Vertex(int x, int y):ID(x), weight(y){};
};

class Graph {
  public:
    // adjacency list
    list<Vertex> *adj;

    // minimum heap
    priority_queue<Vertex, vector<Vertex>, greater<Vertex> > minHeap;

    // Total vertices
    int V;

    Graph(int vertices);
    ~Graph();
    void createAdjacencyList (int src, int dest, int weight);
    void shortestPath (Vertex startNode);
};

Graph::Graph(int vertices) {
  this->adj = new list<Vertex> [vertices];
  this->V = vertices;
}

Graph::~Graph () {
  // free up the adjacency list
    delete adj;
}

void Graph::createAdjacencyList(int src, int dest, int weight) {
  adj[src].push_back(Vertex(dest, weight));
}

void Graph::shortestPath(Vertex startNode) {

  vector<int> distances(this->V, INT_MAX);

  distances[startNode.ID] = startNode.weight;

  minHeap.push(startNode);

  while (!minHeap.empty()) {
    Vertex x = minHeap.top();
    minHeap.pop();

    list<Vertex>::iterator it;

    for (it = adj[x.ID].begin(); it != adj[x.ID].end(); ++it) {

      if (distances[it->ID] > it->weight + x.weight) {
        distances[it->ID] = x.weight + it->weight;
        it->weight = distances[it->ID];
        minHeap.push(*it);
      }
    }
  }
}

*/
