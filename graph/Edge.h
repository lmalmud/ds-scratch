/*
  Edge.h

  A connection between two vertices.
 */

#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

template <typename T>
class Edge {
 public:
  Vertex<T>* head;
  Vertex<T>* tail;

  // Default constructor
 Edge(Vertex<T>* h, Vertex<T>* t) :
  head(h), tail(t) {}
};

#endif
