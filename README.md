# CSCI335-Project5
Graphs

For this program we worked with the ADT known as Graphs.
We represented a graph using an adjacency list, and showed the distance 
between certain vertices in the graph.
We also implemented Dijkstra’s algorithm, using	a priority queue.
And finally we implemented topological sorting on the graph.

You can compile everything by typing 

make clean
make all

-------------------------------------------------------------------------------------------------------
(i). All parts of the assignment were executed
	PART(1).
	Read a directed	graph from a text file.
	Represent a graph using an adjacency list.
	In order to test your implementation will also read a second text file (AdjacencyQueries.txt) that
	will contain a set of pair of vertices.	
	Program	(CreateGraphAndTest) will have to first create the graph by reading it from text file Graph1.txt.
	It will then open the file AdjacenyQueries.txt and for each pair of vertices in it we cout whether the 
	vertices are adjacent or not, and if they are we cout the weight of the edge that connects them.	 


	PART(2).
	Implement Dijkstra’s algorithm, using a priority queue.
	Use Dijkstra’s Algorithm to find the shortest paths from a given starting vertex to all vertices in 
	the graph file.
	Print out the paths to every destination.

	
	PART(3).
	Compute	a sequence of vertices that satisfy the topological sorting sequence.


(ii). There are no known bugs in the program. 


(iii). To run the following program:
	PART(1).
	You can compile by typing 
	make clean
	make all

	Created	a driver program that will be executed as follows:
	./CreateGraphAndTest <Graph_file> <AdjacencyQueries_file>
	where <Graph_file> is the graph.txt file and <AdjacencyQueries_file> 
	is the text file where we will check if	the vertices in the file are adjacent. 

	For example you can run
	./CreateGraphAndTest Graph1.txt	AdjacencyQueries1.txt

	If the file Graph1.txt contains
	5
	1	2	0.2	4	10.1	5 0.5
	2	1 	1.5
	3	2	100.0	4 50.2
	4
	5	2	10.5	3 13.9

	And the file AdjacencyQueries1.txt contains
	4	1
	3	4
	1	5
	5	1
	1	3

	Then the output should be	
	4	1:	Not connected
	3	4:	Connected, weight of edge is 50.2
	1	5:	Connected, weight of edge is 0.5
	5	1:	Not connected
	1	3:	Not connected


	PART(2).
	You can compile by typing 
	make clean
	make all

	The executable should run using parameters:
	./FindPaths <GRAPH_FILE> <STARTING_VERTEX>

	where <STARTING_VERTEX> is the integer of the vertex you want to start from.
	
	For example if you run the program having as input Graph2.txt starting from vertex 1, i.e.
	./FindPaths Graph2.txt	1
	Then	the	output	should	be
	1:1	 	(Cost: 0)
	2:1, 2	 	(Cost: 2.0)
	3:1, 4, 3 	(Cost: 3.0)
	4:1		(Cost: 1)
	5:1, 4, 5	(Cost:	3)
	6:1, 4, 7, 6 	(Cost: 6)
	7:1, 4, 7	(Cost:	5)


	PART(3).
	You can compile by typing 
	make clean
	make all

	The executable should run using parameters:
	./TopologicalSort <GRAPH_FILE>

	The output should be the sequence of vertices. If a cycle is detected, just print the message
	“Cycle found” and terminate the program.

	For Example:
	./TopologicalSort Graph2.txt
	should produce the message
	“Cycle	found”
	Since there is not a vertex with indegree zero in the graph.

	OR 

	./TopologicalSort Graph3.txt
	should produce the sequence
	1, 2, 5, 4, 3, 7, 6.


(iii). Provided with three simple graphs to start and debug program with.
	For graphs 2 and 3 provided with a picture corresponding to the	input text file.
	As well as 2 AdjacencyQueries files to test part(1) with.
