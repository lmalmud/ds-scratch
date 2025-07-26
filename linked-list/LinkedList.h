/*
  LinkedList.h
  Interface for an integer-storing linked list.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinekdList {
 private:
  Node* head;
  Node* tail;
  int length;

 public:
  // Add a value to the end of the list.
  // @param value: integer to append
  static void append(int value);

  // Output the length and content
  // of list to the screen.
  static void print();
};

#endif
