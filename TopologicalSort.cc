//	Alfredo Morales
//	Driver program that prints out the implementation of Topological Sorting
//	For each vertex you have a list of the adjacent vertices with positive edge weights.

#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void TopSort(const string& words_filename) {
	cout << "TestFunctionForTopologicalSorting..." << endl;
	cout << "Input file: " << words_filename << endl;

	/*------------------------------------READ WORD FILE PROCEDURE--------------------------------------------------------*/
	ifstream file_input;

	file_input.open(words_filename);

	if (file_input.fail()) {
		cout << "ERROR WHILE OPENING WORDS FILE" << endl;
	}
	/*--------------------------------------------------------------------------------------------------------------------*/

	string new_line;
	int numberOfVertices = 0;

	//Get the number of nodes in this adjacency list
	file_input >> numberOfVertices;
	// Create an object Test of type Graph
	Graph Test(numberOfVertices);

	/*-------------------------------------  FILL IN GRAPH PROCEDURE  -----------------------------------------------------*/
	//This process is explained in CreateGraphAndTest.cc file

	while (getline(file_input, new_line)) //Read all words from a given text file
	{
		int iter = 1;
		int vertex = 0;
		int connectedVertex = 0;
		double weightOfEdge = 0;

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
	cout << "Topological Sort implementation on graph... " << endl;
	Test.TopologicalSort();
}

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <InputFile> " << endl;
		return 0;
	}
	const string words_filename(argv[1]);
	TopSort(words_filename);
	return 0;
}
