/*
  graph_test.cpp

  Implementation of unit test for graph class.

  g++ -std=c++17 graph_test.cpp
 */

#include <iostream>
#include <cassert>
#include "Graph.h"

int main(int argc, char** argv) {

  // Create graph and add one vertex
  Graph<int> graph1 = Graph<int>();
  assert(graph1.vertices.size() == 0);
  graph1.add_vertex(1);
  assert(graph1.vertices.size() == 1);

  graph1.add_vertex(2);
  graph1.add_vertex(3);
  graph1.add_vertex(4);
  graph1.add_vertex(5);
  graph1.add_vertex(6);
  assert(graph1.vertices.size() == 6);

  // Add edges
  graph1.add_edge(1, 2);
  graph1.add_edge(1, 3);
  assert(graph1.adj_vertices(1).size() == 2); // Node 1 should now have two adjacent vertices
  graph1.add_edge(3, 5);
  assert(graph1.adj_vertices(3).size() == 1); // Node 2 should now have one adjacent vertex
  graph1.add_edge(2, 4);
  graph1.add_edge(4, 5);
  graph1.add_edge(4, 6);

  // Display adjacency matrix to the screen
  graph1.print_adj();

  // Attempt to add an edge that already exists, ensure it isn't duplicated
  graph1.add_edge(4, 5);
  assert(graph1.adj_vertices(4).size() == 2);
  
  return 0;
}
