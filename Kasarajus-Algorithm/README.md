# The Kosaraju Algorithm for finding the top five strongly connected components in a directed graph.

This program basically finds the top five strongly connected components of the directed graphs given in the Data directory. 
For larger directed graphs with an elephentine number of vertices, the following steps can be taken on the linux machine:

- Open the terminal
- Type ulimit -s unlimited

This step is taken in order to increase the amount of space used by the stack for this particular program so as to compensate for the memory to be used by the large number of vertices.

CAUTION: Using the "unlimited" keyword with ulimit can lead to system failure so care should be taken when using this.

To compile, download the program folder and compile it by typing make and then execute it from the bin directory by typing ./SCC

![alt tag] (https://upload.wikimedia.org/wikipedia/commons/6/60/Tarjan's_Algorithm_Animation.gif)
