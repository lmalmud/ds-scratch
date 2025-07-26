/*
  Node.cpp
*/

// Includes the header file
// Including a header file eliminates redundancy in having
// declare the same functions multiple times.
// This also allows for faster compilation, essentially
// pasting the function prototypes.
#include "Node.h"

Node::Node(int value, Node* next) {
  this->value = value;
  this->next = next;
}
