/*
  LinkedList.cpp
  
*/

#include "Node.h"
#include <iostream>

LinkedList::LinkedList() {
  this->head = NULL;
  this->length = 0;
}

LinkedList::append(int value) {
  Node newNode  = Node(value, NULL);

  // If there are currently no items in the list
  if (this->length == 0) {
    this->head = &newNode;
    this->tail = &newNode;

  // If there is at least one item, add after tail and update
  } else {
    this->tail->next = &newNode;
    this->tail = &newNode;
  }

  this->length++;
}

LinkedList::print() {
  std::count << "length: " << this->length << std::endl;
}
