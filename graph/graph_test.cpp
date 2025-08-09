/*
  graph_test.cpp

  Implementation of unit test for graph class.
 */

#include <iostream>
#include <cassert>
#include "Graph.h"

int main(int argc, char** argv) {

  Graph<int> graph1 = Graph<int>();
  graph1.add_vertex(1);
  
  std::cout << graph1.vertices.size() << std::endl;
  
  return 0;
}
