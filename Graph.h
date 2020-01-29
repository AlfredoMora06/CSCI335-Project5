//Alfredo Morales
//Graph.h file, implements all 3 parts of the project and inherits from 
//Vertex.h and Adjacent.h

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <limits>
#include <vector> 
#include <queue> 
#include "Adjacent.h"
#include "Vertex.h"
using namespace std;


class Graph
{
public:
	Graph() {}


	/*
		Helper function that comes in handy to add the adjacent vertex to the adjacency list vector
		also factors in the cost
	*/
	void addToEdge(const int& a_vertex, const int& an_adjacent_vertex, const float& cost) {
		AdjacentPoint adj_object(an_adjacent_vertex, cost);
		//Looks to the previous vertex in the vector 
		//and the adjacency list 
		//points to the Adjacency list 
		vertices[a_vertex]->adjacency_list.push_back(adj_object);
	}

	Graph(const int& num_of_vertices) : vertices(num_of_vertices + 1)
	{
		size_t inf = numeric_limits<int>::max();

		for (int i = 1; i < num_of_vertices + 1; i++)
		{
			vertices[i] = new Vertex(i, false, inf, 0, 0, nullptr);
		}
	}//end one param constructor 

	struct CompareVertices
	{
		bool operator() (const Vertex* v1, const Vertex* v2) const
		{
			return v1->distance > v2->distance;
		}
	}; 

	/*
	Graph Representation (PART 1)
	For each vertex you have a list of the adjacent vertices with positive edge weights. 
	Represent a graph using an adjacency list. 
	In order to	test implementation, also read a second	text file (AdjacencyQueries1.txt) that will contain a set of pair of vertices.
	(^^ In CreateGraphAndTest.cc program ^^)
	Method checks for each pair of vertices in	it, couts whether the vertices are adjacent or not, and	if they are	it couts the weight
	of the edge that connects them.
	*/
	void CheckConnections(int vertex1, int vertex2)
	{
		bool connected = false;
		size_t sizeOfList = vertices[vertex1]->adjacency_list.size();

		//loop through the vertices
		for (unsigned int i = 0; i < sizeOfList; i++){
			//if two vertex are adjacent...
			if (vertices[vertex1]->adjacency_list[i].vertex == vertex2){
				connected = true;
				cout << vertex1 << " " << vertex2 << ": Connected, weight of edge is " 
					<< vertices[vertex1]->adjacency_list[i].weight_amount << endl;
				break;
			}
		}
		if (connected == false) {
			cout << vertex1 << " " << vertex2 << ": Not Connected " << endl;
		}
	}

	/*
	Dijkstra’s Algorithm Implementation (PART 2)
	Implemented Dijkstra’s Algorithm, using a priority queue.
	This program should	use	Dijkstra’s Algorithm to find the shortest paths from a given starting vertex to all	
	vertices in the graph file. 
	The program	should output all paths in the form:
	Destination: Start, V1, V2, … , Destination, (Total cost: X)
	You should print out the paths to every destination.
	*/
	void Dijkstra(int v)
	{
		vertices[v]->distance = 0;
		priority_queue <Vertex*, vector<Vertex*>, CompareVertices> min_priority_queue; //declare the queue
		min_priority_queue.push(vertices[v]);

		while (!(min_priority_queue.empty()))
		{
			Vertex* v = min_priority_queue.top();
			min_priority_queue.pop();
			v->flag = true;

			//for each element in my adjacency list
			for (unsigned int i = 0; i < v->adjacency_list.size(); i++)
			{
				//setlook at each vertex
				int v_num = v->adjacency_list[i].vertex;
				Vertex* unknown_v = vertices[v_num];

				if (!unknown_v->flag)
				{
					float c = v->adjacency_list[i].weight_amount; //gets the cost associated with each vertex
					//if the distance between the current vertex and th
					if (v->distance + c < unknown_v->distance)
					{
						unknown_v->distance = v->distance + c;
						unknown_v->path = v;
					}
					min_priority_queue.push(unknown_v);
				}

			}
		}

		//Print the Shortest Path for each vertex
		for (unsigned int i = 1; i < vertices.size(); i++)
		{
			cout << vertices[i]->vertex_amount << ": ";
			double shortest_path = vertices[i]->distance;

			PrintPath(vertices[i]);
			if (shortest_path != numeric_limits<int>::max())
			{
					cout.precision(1);
					cout << fixed;

					cout << "(Cost: " << shortest_path << ")" << endl;
			}
			else
				cout << "ERROR" << endl; //no path exists
		}
	}
	/*
	Topological	Sorting (PART 3)
	Methods	compute a  sequence of vertices that satisfy the topological sorting sequence	
	The	output should be the sequence of vertices. 
	If a cycle is detected, just print the message “Cycle Found” and terminate the program.
	*/
	void TopologicalSort() {
		size_t sizeOfVertices = vertices.size();

		for (unsigned int i = 1; i < sizeOfVertices; i++) {
			for (unsigned int j = 0; j < vertices[i]->adjacency_list.size(); j++) {
				int adj = vertices[i]->adjacency_list[j].vertex;
				vertices[adj]->indegree++;
			}
		}

		queue<Vertex*> queue_list;
		int counter = 0;
		

		for (unsigned int i = 1; i < sizeOfVertices; i++) {
			if (vertices[i]->indegree == 0) {
				queue_list.push(vertices[i]);
			}
		}

		while (queue_list.empty() == false) {
			Vertex* temp_vertex = queue_list.front();
			cout << temp_vertex->vertex_amount;
			queue_list.pop();

			temp_vertex->initial_num = counter++;

			for (unsigned int j = 0; j < temp_vertex->adjacency_list.size(); j++) {
				Vertex* some = vertices[temp_vertex->adjacency_list[j].vertex];
				some->indegree--;	//decease indegree

				if (some->indegree == 0) {
					queue_list.push(some); // enqueue it
				}
			}
			if (queue_list.empty() == true) 
			{
				cout << ".";
			}
			else 
			{
				cout << ",";
			}
		}

		int num_vertices = vertices.size() - 1;
		if (counter != num_vertices) {
			cout << "Cycle Found!" << endl;
		}
		else {
			cout << endl;
		}
	}
	~Graph() {};

	private:
		void PrintPath(Vertex* vertex1) {
			if (vertex1->path != nullptr) {
				//next vertex
				PrintPath(vertex1->path);
			}
			cout << vertex1->vertex_amount << " ";
		}

		//store the vertex from graph
		vector<Vertex*> vertices;
};



#endif