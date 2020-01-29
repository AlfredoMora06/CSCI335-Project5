//Alfredo Morales
//Constructor of a vertex to be read by the file, 
//it has a vertex and weight amount to initialize these variables
//Made to facilitate accesssing.

#ifndef ADJACENT_POINT_H
#define ADJACENT_POINT_H
#include <iostream>
using namespace std;

class AdjacentPoint{
public: 
    int vertex;
    float weight_amount; 

    AdjacentPoint(const int &vertex_, const float &cost_):vertex{vertex_},weight_amount{cost_}{}
};

#endif

