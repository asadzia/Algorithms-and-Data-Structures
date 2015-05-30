/*
*
* An adjacency list representation of an undirected graph in C.
*
*
* Created by: Asad Zia.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct Graph
{
	int Vertices;
	struct node** array;
};

/*
* The function for creating a new node
*/
struct node* newNode (int data)
{
	struct node* N = (struct node*)malloc(sizeof(struct node));
	if (N == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	N->data = data;
	N->next = NULL;
	return N;
}

/*
* The function for building a graph
*/
struct Graph* buildGraph(int nodes)
{
	int i;

	struct Graph* myGraph = (struct Graph*)malloc(sizeof(struct Graph));
	if (myGraph == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	myGraph->array = (struct node**)malloc(sizeof(struct node*) * nodes);
	if (myGraph->array == NULL)
	{
		printf("Error in memory allocation!\n");
		exit(1);
	}

	for (i = 0; i < nodes; i++)
	{
		myGraph->array[i] = NULL;
	}

	myGraph->Vertices = nodes;
	return myGraph;
}

/*
* A function for adding the edges.
* Since we are depicting an undirected graph, the edge is added to both the source and destination node.
*/
void addEdge (struct Graph* myGraph, int src, int dest)
{
	struct node* N = newNode(dest);

	if (myGraph->array[src] == NULL)
	{
		myGraph->array[src] = N;
	}
	else
	{
		N->next = myGraph->array[src];
		myGraph->array[src] = N;	
	}
	

	struct node* NN = newNode(src);

	if (myGraph->array[dest] == NULL)
	{
		myGraph->array[dest] = NN;
	}
	else
	{
		NN->next = myGraph->array[dest];
		myGraph->array[dest] = NN;
	}
}

/*
* A function for printing the adjacency lists of the graph
*/
void printGraph (struct Graph* myGraph)
{
	int i;
	struct node* temp;

	for (i = 0; i < myGraph->Vertices; ++i)
	{
		temp = myGraph->array[i];
		printf("Adjacency list for %d:\n", i);

		while (temp != NULL)
		{
			printf("%d - ", temp->data);
			temp = temp->next;
		}
		printf("\n\n");
	}
}

/*
* The function to free the graph and its compnonents.
*/
void freeGraph (struct Graph* myGraph)
{
	int i;
	struct node* temp, * cur;

	for (i = 0; i < myGraph->Vertices; i++)
	{
		cur = myGraph->array[i];

		while (cur != NULL)
		{
			temp - cur->next;
			free(cur);
			cur = temp;
		}
	}
	free(myGraph->array);
	free(myGraph);
}

/*
* The main function
*/
int main()
{
    int V = 5;
    struct Graph* graph = buildGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
	freeGraph(graph);
	 
    return 0;
}
