/*
  LinkedList.h
  Interface for an integer-storing linked list.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
 private:
  Node* head;
  Node* tail;

 public:
  // Default constructor
  LinkedList();
  
  // Add a value to the end of the list.
  // @param value: integer to append
  void append(int value);

  // Output the length and content
  // of list to the screen.
  void print();

  // Length of list
  int length;
};

#endif
