/*
  Graph.cpp

  Implementation of graph funciton.
 */

#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

#include <vector>

template <typename T>
Graph<T>::Graph() {
  
}

template <typename T>
void Graph<T>::add_vertex(T val) {
  Vertex<T> newVertex(val); // Create vertex with new value
  this->vertices.push_back(newVertex); // Add to vector of vertices
}
