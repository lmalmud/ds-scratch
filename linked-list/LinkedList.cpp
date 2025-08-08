/*
  LinkedList.cpp
  
*/

#include "Node.h"
#include "LinkedList.h"
#include <iostream>
LinkedList::LinkedList() {
  this->head = nullptr;
  this->length = 0;
}

void LinkedList::append(int value) {
  // Allocate new Node
  Node* newNode  = new Node(value, nullptr);

  // If there are currently no items in the list
  if (this->length == 0) {
    this->head = newNode;
    this->tail = newNode;

  // If there is at least one item, add after tail and update
  } else {
    this->tail->next = newNode;
    this->tail = newNode;
  }

  this->length++;
}

void LinkedList::print() {
  std::cout << "[";
  Node* current = this->head;
  int i = 0;
  while (i < this->length) {
    //std::cout << current->value << ", ";
    current->print();
    current = current->next;
    i++;
  }
  std::cout << "]";
}
