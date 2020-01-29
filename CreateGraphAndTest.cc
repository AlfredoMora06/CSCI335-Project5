	//	Alfredo Morales
	//	Program will read a directed graph from a text file.
	//	For each vertex you have a list of the adjacent vertices with positive edge weights.

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void TestGraph(const string& words_filename, const string& query_filename){
	cout << "TestFunctionForGraphRepresentation..." << endl;
	cout << "Input file: " << words_filename << endl;
	cout << "Test filename: " << query_filename << endl;

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
	while (getline(file_input, new_line)) //Read all words from a given text file
	{
		/*We want iter to be 1 because we want to read the number of vertices from the beginning
		 *of the first line
		 */
		int iter = 1;
		int vertex = 0;
		int connectedVertex = 0;
		double weightOfEdge = 0;
		
		stringstream streamObject(new_line);	//The line from the file in new_line
		//By this line number of vertices has already been read.
		while (streamObject)
		{
			//1< 2 0.2 4 10.1 5 0.5
			//The first input (in this case 5) determines the number of vertices
			if (iter == 1)
				//5
				//1< 2 0.2 4 10.1 5 0.5
				streamObject >> vertex;
			//5
			//1 2< 0.2 4 10.1 5 0.5
			//The connected vertex is now read 
			streamObject >> connectedVertex;
			//5
			//1 2 0.2< 4 10.1 5 0.5
			//The weight of the edge connecting the two previous vertexes is read now
			streamObject >> weightOfEdge;
			if (streamObject)
				Test.addToEdge(vertex, connectedVertex, weightOfEdge);
			iter++;
		}
	}

	cout << "Graph was read succesfully!" << endl << endl;
	/*--------------------------------------------------------------------------------------------------------------------*/

	int vertex1 = 0;
	int vertex2 = 0;
	
	//-----------------------------------READ ADJACENT FILE PROCEDURE---------------------------------------------------------/
	ifstream adjacent_file;
	adjacent_file.open(query_filename);

	if (adjacent_file.fail()) {
		cout << "ERROR WHILE OPENING WORDS FILE" << endl;
	}
	//-------------------------------------------------------------------------------------------------------------------------/

	//Continue checking until you reach the end of the file
	while (!(adjacent_file.eof()))
	{
		adjacent_file >> vertex1;
		adjacent_file >> vertex2;
		Test.CheckConnections(vertex1, vertex2);

	}
}

int main(int argc, char** argv){
	if (argc != 3){
		cout << "Usage: " << argv[0] << " <InputFile> <SearchFile>" << endl;
		return 0;
	}
	const string words_filename(argv[1]);
	const string query_filename(argv[2]);
	TestGraph(words_filename, query_filename);
	return 0;
}
