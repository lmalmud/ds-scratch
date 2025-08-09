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
  std::vector<T> vertices;
  std::map<T, std::vector<T> > edge_adj;

  // Default constructor
  Graph();

  // Deconstructor
  ~Graph();

  // Adds a new vertex.
  // @param val: value of the node to be inserted.
  void add_vertex(T val);

  // Adds a new edge to the graph between two vertices.
  // @param source: vertex the edge eminates from
  // @param dest: vertex the edge points to
  void add_edge(T source, T dest);

  // Returns a list of vertices that are adjacent to the
  // specified node.
  // @param source: node to look for adjacent vertices from
  // @return: a vector containing adjacent nodes
  std::vector<T> adj_vertices(T source);

  // Displays the adjacency list representing the graph.
  void print_adj();

  // Performs BFS starting at the specefied source.
  // @param source: location to start BFS
  std::vector<T> bfs(T source);

  // Performs DFS starting at the specefied source.
  // @param dest: location to start DFS
  std::vector<T> dfs(T source);

 private:

  // Print a vector.
  void print_vector(const std::vector<T>& v);
};

#include "Graph.tpp" // Include template definitions
#endif
