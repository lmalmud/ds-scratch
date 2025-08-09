/*
  graph_test.cpp

  Implementation of unit test for graph class.

  g++ -std=c++17 graph_test.cpp
 */

#include <iostream>
#include <cassert>
#include "Graph.h"

// Assets that two vectors contain the same elements.
// @param v1, v2: the two vectors to compare
void assertVectors(std::vector<int> v1, std::vector<int> v2) {
  assert(v1.size() == v2.size());
  for (int i = 0; i < v1.size(); ++i) {
    assert(v1.at(i) == v2.at(i));
  }
}

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

  // Perform BFS starting from node 1
  std::vector<int> bfsResult1 = graph1.bfs(1);
  std::vector<int> bfsResultTrue1 = {1, 2, 3, 4, 5, 6};
  assertVectors(bfsResult1, bfsResultTrue1);

  // Perform DFS starting from node 1
  std::vector<int> dfsResult1 = graph1.dfs(1);
  std::vector<int> dfsResultTrue1 = {1, 3, 5, 2, 4, 6};
  assertVectors(dfsResult1, dfsResultTrue1);

  // Find te length of the shortest path between 1 and 4
  assert(graph1.shortest_path(1, 4) == 2);
  
  
  return 0;
}
