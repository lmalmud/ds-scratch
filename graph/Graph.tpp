/*
  Graph.tpp

  Implementation of graph funciton.

  To open in C++ mode:
  emacs --eval "(progn (find-file \"Graph.tpp\") (c++-mode))"
 */

// Do not need to include Graph.h, since this file is included *by* Graph.h

#include <algorithm> // For std::find in std::vector

template <typename T>
Graph<T>::Graph() = default;

template <typename T>
Graph<T>::~Graph() {

}

template <typename T>
void Graph<T>::add_vertex(T val) {
  this->vertices.push_back(val); // Add to vector of vertices
}

template <typename T>
void Graph<T>::add_edge(T source, T dest) {

  // If this vertex does not currently have any adjacent edges
  /*
  if (this->edges.count(source) == 0) {
     this->edges[source] = 
  }
  if (std::find(
  */
  // Only add if vertex is not already adjacent
  if (std::find(this->edge_adj[source].begin(),
		this->edge_adj[source].end(),
		dest) == this->edge_adj[source].end()) {
    this->edge_adj[source].push_back(dest);
  }
}

template <typename T>
std::vector<T> Graph<T>::adj_vertices(T source) {
  return this->edge_adj[source];
}

template <typename T>
void Graph<T>::print_adj() {
  for (typename std::map<T, std::vector<T> >::const_iterator it = this->edge_adj.begin();
       it != this->edge_adj.end();
       it++) {

    // vertex: adjacency list for each vertex is printed
    std::cout << it->first << ": ";
    this->print_vector(it->second);
    std::cout << std::endl;
  }
}

template <typename T>
void Graph<T>::print_vector(const std::vector<T>& v) {
  std::cout << "[";

  // For each element in the range
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v.at(i);

    // Only print comma if there is another element
    if (i < v.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]";
}

template <typename T>
void Graph<T>::bfs(T source) {

}

template <typename T>
void Graph<T>::dfs(T source) {

}
