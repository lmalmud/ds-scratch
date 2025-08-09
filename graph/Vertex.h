/*
  Vertex.h

  A node in a graph.
 */

#ifndef VERTEX_H
#define VERTEX_H

template <typename T>
class Vertex {
 public:
  T data;

  // Default constructor
 Vertex(T data) : data(data) {}
};

#endif
