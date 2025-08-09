/*
  Graph.h
  ADT for graph implemented with an adjacency list.
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector> // For vertices
#include <map> // For adjacency list

template <typename T>
class Graph {
 public:
  std::vector<Vertex<T> > vertices;
  std::vector<Vertex<T>, std::vector<Vertex<T> > > edge_adj;

  // Default constructor
  Graph();

  // Adds a new vertex.
  // @param val: value of the node to be inserted.
  void add_vertex(T val);

  // Adds a new edge to the graph between two vertices.
  // @param source: vertex the edge eminates from
  // @param dest: vertex the edge points to
  void add_edge(T source, T dest);
};

template <typename T>
Graph<T>::Graph() = default;

#endif
