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
  // Allocate new Node- need to use the new keyword, otherwise allocated on the stack
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

  // Keep printing as long as there are more items
  while (i < this->length) {
    std::cout << current->value;

    // Only print a comma if there is another element afterwards
    if (i < this->length - 1) {
      std::cout << ", ";
    }

    // Traverse to the next node and increment counter
    current = current->next;
    i++;
  }
  std::cout << "]" << std::endl;
}

int LinkedList::first() {
  return this->head->value;
}

int LinkedList::last() {
  return this->tail->value;
}

void LinkedList::remove(int i) {
  if (this->length == 1) { // Case when there is only one element
    delete this->head;
    delete this->tail;
    this->head = nullptr;
    this->tail = nullptr;
  } else if (i == 0) { // Delete from front - must update head
    Node* oldHead = this->head; // Keep pointer to old head
    this->head = this->head->next; // Skip the first element
    delete oldHead; // Delete the old one
  } else if (i == this->length - 1) {

  } else {

  }

  this->length--;
}
