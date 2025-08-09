/*
  Graph.tpp

  Implementation of graph funciton.

  To open in C++ mode:
  emacs --eval "(progn (find-file \"Graph.tpp\") (c++-mode))"
 */

// Do not need to include Graph.h, since this file is included *by* Graph.h

#include <algorithm> // For std::find in std::vector
#include <queue> // For std::queue in BFS
#include <stack> // For std::stack in DFS

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
       ++it) {

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
std::vector<T> Graph<T>::bfs(T source) {
  std::queue<T> q; // Queue of nodes to next visit
  q.push(source);
  
  std::map<T, bool> visited; // Track whether each node *has* been visited
  for (typename std::vector<T>::const_iterator it = this->vertices.begin();
       it != this->vertices.end(); ++it) {
    visited[*it] = false;
  }
  
  std::vector<T> res; // Resulting order that nodes are traversed in

  while(!q.empty()) { // While there are still nodes to visit
    T current = q.front(); // Fetch the next node to visit
    q.pop(); // Dequeue the next element (front only peeks, doesn't return)
    res.push_back(current);
    visited[current] = true; // Mark node as visited

    // Explore all neighbors
    for (typename std::vector<T>::const_iterator it = this->edge_adj[current].begin();
	 it != this->edge_adj[current].end(); ++it) {

      // If this node has not yet been visited, enqueue it.
      if (!visited[*it]) {
	q.push(*it);
	visited[*it] = true; // Mark neighbor as visited
      }
      
    }
  }

  return res;
}

template <typename T>
std::vector<T> Graph<T>::dfs(T source) {
  std::stack<T> s;

  // Initially, each node is not visited
  std::map<T, bool> visited;
  for (typename std::vector<T>::const_iterator it = this->vertices.begin();
       it != this->vertices.end(); ++it) {
    visited[*it] = false;
  }
  
  std::vector<T> res;

  s.push(source);

  while(!s.empty()) {
    T current = s.top(); // Access next element
    s.pop();
    res.push_back(current);
    visited[current] = true;

    for (typename std::vector<T>::const_iterator it = this->edge_adj[current].begin();
	 it != this->edge_adj[current].end(); ++it) {
      // If the neighbor is not visited: enqueue it and mark as visited
      if (!visited[*it]) {
	s.push(*it);
	visited[*it] = true;
      }
    }
  }

  return res;
}

template <typename T>
int Graph<T>::shortest_path(T s, T t) {

}
