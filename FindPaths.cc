//Alfredo Morales
//Driver program that prints out the implementation of Dijkstra's algorithm using a priority queue
//Located in Graph.h

#include <iostream>
#include <string>
#include <sstream> 
#include  <fstream> 
#include "Graph.h"
using namespace std;

void TestFindPaths(const string& words_filename, const double& starting_vertex) 
{
	cout << "TestFunctionForDijkstra..." << endl;
	cout << "Input Graph File: " << words_filename << endl;

	/*------------------------------------READ WORD FILE PROCEDURE--------------------------------------------------------*/
	ifstream file_input;
	file_input.open(words_filename);

	if (file_input.fail()) {
		cout << "ERROR WHILE OPENING GRAPH TEXT FILE" << endl;
	}
	/*--------------------------------------------------------------------------------------------------------------------*/

	string new_line;
	int numberOfVertices = 0;

	//Get the number of nodes in this adjacency list
	file_input >> numberOfVertices;
	// Create an object Test of type Graph
	Graph Test(numberOfVertices);

	/*-------------------------------------  FILL IN GRAPH PROCEDURE  -----------------------------------------------------*/
	//This process is explained more in CreateGraphAndTest.cc file

	while (getline(file_input, new_line)) //Read all words from a given text file
	{
		int iter = 1;
		int vertex = 0;
		int connectedVertex = 0;
		float weightOfEdge = 0.0;

		stringstream streamObject(new_line);
		while (streamObject)
		{
			if (iter == 1) 
			{
				streamObject >> vertex;
			}
			streamObject >> connectedVertex;

			streamObject >> weightOfEdge;
			if (streamObject) 
			{
				Test.addToEdge(vertex, connectedVertex, weightOfEdge);
			}
			iter++;
		}
	}
	cout << "Graph was read succesfully!" << endl << endl;
	/*--------------------------------------------------------------------------------------------------------------------*/

	cout << "Dijkstra implementation on vertex " << starting_vertex <<  endl;

	//Run Dijkstra located in Graph.h file
	Test.Dijkstra(starting_vertex);
}


int main(int argc, char **argv){
    if (argc != 3)
	{
		cout << "Usage: " << argv[0] <<" <GRAPH_FILE> <STARTING_VERTEX>" << endl;
		return 0;
	}
	const string create_graph_file (argv[1]);
	double starting_vertex = atoi(argv[2]);

	TestFindPaths(create_graph_file, starting_vertex);
	return 0;
}