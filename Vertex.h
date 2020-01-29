#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
#include "Adjacent.h"
using namespace std;

class Vertex{
//This is a vertex class, made to access elements in graph easier.
public: 
    Vertex(const int& vertex_count_,const bool& fl, const float& distance_, const int indegree_, const int initial_number,Vertex* route_){
        vertex_amount = vertex_count_;
        flag = fl;
        distance = distance_;
        initial_num = initial_number;
        indegree = indegree_; 
        path = route_; 
    }
	//Properties of a vector
    int vertex_amount;
    Vertex* path;
    float distance; 
    int indegree;
    int initial_num; 
    bool flag; 
	//vector of all the adjacent vetrteces to your current vertex
    vector<AdjacentPoint> adjacency_list; 

  

    
};

#endif