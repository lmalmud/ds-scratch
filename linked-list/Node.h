/*
  Node.h
  Interface for a node as a unit in a linked list
  that stores integer values.
*/

#ifndef NODE_H
#define NODE_H

class Node {
 public:
  int value;
  Node* next;

  // Default constructor
  Node(int value, Node* next);

  void print();
};

#endif
