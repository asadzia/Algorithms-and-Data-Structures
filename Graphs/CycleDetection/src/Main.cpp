/*
*
* A program to detect a cycle in a graph in C++.
*
*
* Created By: Asad zia
*/

#include "Cycle.h"

int main()
{
    Graph myGraph(4);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 0);
    myGraph.addEdge(2, 3);
    myGraph.addEdge(3, 3);
 
    if(myGraph.CycleDetection())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
