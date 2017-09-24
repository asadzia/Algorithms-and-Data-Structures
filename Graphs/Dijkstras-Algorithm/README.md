# Dijkstra's Algorithm for finding the Shortest Path from a single source.

Djikstra's algorithm (named after its discover, E.W. Dijkstra) solves the problem of finding the shortest path from a point in a graph (the source) to a destination. It turns out that one can find the shortest paths from a given source to all points in a graph in the same time, hence this problem is sometimes called the single-source shortest paths problem.

The somewhat unexpected result that all the paths can be found as easily as one further demonstrates the value of reading the literature on algorithms!
This problem is related to the spanning tree one. The graph representing all the paths from one vertex to all the others must be a spanning tree - it must include all vertices. There will also be no cycles as a cycle would define more than one path from the selected vertex to at least one other vertex. 

For a graph,
G = (V,E)	where,	
- V is a set of vertices and
- E is a set of edges.

Dijkstra's algorithm keeps two sets of vertices:
- S	 	the set of vertices whose shortest paths from the source have already been determined and
- V-S	 	the remaining vertices.

The other data structures needed are:
- d	array of best estimates of shortest path to each vertex
- pi	an array of predecessors for each vertex

The basic mode of operation is:

  Initialise d and pi,<br />
  Set S to empty,<br />
  While there are still vertices in V-S,<br />
  Sort the vertices in V-S according to the current best estimate of their distance from the source,<br />
  Add u, the closest vertex in V-S, to S,<br />
  Relax all the vertices still in V-S connected to u<br />
  Relaxation<br />

The relaxation process updates the costs of all the vertices, v, connected to a vertex, u, if we could improve the best estimate of the shortest path to v by including (u,v) in the path to v.

The relaxation procedure proceeds as follows:

initialise_single_source( Graph g, Node s )<br />
   for each vertex v in Vertices( g )<br />
       g.d[v] := infinity<br />
       g.pi[v] := nil<br />
   g.d[s] := 0;<br />
   
This sets up the graph so that each node has no predecessor (pi[v] = nil) and the estimates of the cost (distance) of each node from the source (d[v]) are infinite, except for the source node itself (d[s] = 0).

Note that we have also introduced a further way to store a graph (or part of a graph - as this structure can only store a spanning tree), the predecessor sub-graph - the list of predecessors of each node,<br />
pi[j], 1 <= j <= |V|
<br />
The edges in the predecessor sub-graph are (pi[v],v).

The relaxation procedure checks whether the current best estimate of the shortest distance to v (d[v]) can be improved by going through u (i.e. by making u the predecessor of v):

relax( Node u, Node v, double w[][] )<br />
    if d[v] > d[u] + w[u,v] then<br />
       d[v] := d[u] + w[u,v]<br />
       pi[v] := u<br />
       
The algorithm itself is now:

  shortest_paths( Graph g, Node s )<br />
      initialise_single_source( g, s )<br />
      S := { 0 }        /* Make S empty */<br />
      Q := Vertices( g ) /* Put the vertices in a PQ */<br />
      while not Empty(Q) <br />
          u := ExtractCheapest( Q );<br />
          AddNode( S, u ); /* Add u to S */<br />
          for each vertex v in Adjacent( u )<br />
              relax( u, v, w )<br />


![Alt Text] (http://algo.ics.hawaii.edu/~nodari/teaching/f15/Notes/Topic-18/Fig-24-6-Dijkstra-Example.jpg)
