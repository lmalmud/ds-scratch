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
  if (this->length == 0) { // Attempt to remove from empty list
    throw std::runtime_error("cannot remove from empty LinkedList");

  } else if (i >= this->length || i < 0) { // Out-of-bounds error
    throw std::runtime_error("index out of bounds when remving from LinkedList");

  } else if (this->length == 1) { // Case when there is only one element
    delete this->head;
    delete this->tail;
    this->head = nullptr;
    this->tail = nullptr;
    
  } else if (i == 0) { // Delete from front - must update head
    Node* oldHead = this->head; // Keep pointer to old head
    this->head = this->head->next; // Skip the first element
    delete oldHead; // Delete the old one
    
  } else if (i == this->length - 1) {
    Node* current = this->head; // Need to traverse to find node before tail
    while(current->next != this->tail) {
      current = current->next;
    }
    // Now, current points to the node *before* tail
    delete this->tail;
    this->tail = current;
    current->next = nullptr; // New last node needs to point to nothing
    
  } else {
    Node* current = this->head;
    int pos = 0;
    // Grab the node *before* the one you want to delete
    while (pos < i-1) {
      current = current->next;
    }
    Node* toRemove = current->next;

    // Change pointer to skip the node to be deleted
    current->next = toRemove->next;
    delete toRemove;
  }

  this->length--;
}

bool LinkedList::find(int value) {
  Node* current = this->head;
  bool found = false;
  while (current != nullptr && (!found)) {
    if (current->value == value) {found = true;}
    current = current->next;
  }
  return found;
}

int LinkedList::get(int i) {
  // Ensure valid index
  if (i >= this->length || i < 0) {
    throw std::runtime_error("cannot access item out of range");
  }

  // Traverse until item is found
  int count = 0;
  Node* current = this->head;
  while (count < i) {
    current = current->next;
    count++;
  }

  return current->value;
}

void LinkedList::remove_value(int value) {
  if (!this->find(value)) { // Throw error if value is not present
    throw std::runtime_error("cannot remove value that is not present");
  } else { // Traverse until value is found to get index, then call remove
    Node* current = this->head;
    int i = 0;
    while (current->value != value) {
      current = current->next;
      i++;
    }

    // Now that we have index, just call other remove function
    // Note that this will be O(2n), whereas if we did pointer logic here
    // we could reduce to O(n) -- but this is insignificant
    this->remove(i);
  }
}
