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

  // Delete item at given index
  // @param i: index to remove from
  // @throws runtime_error: removal from empty list, out of bounds

  void remove(int i);

  // Output the length and content
  // of list to the screen.
  void print();

  // Output the first item in the list
  int first();

  // Output the last item in the list
  int last();

  // Look for an item with the given value
  // @param value: target value within list
  // @return: true if value is present and false otherwise
  bool find(int value);

  // Remove a particular value
  // @param value: value to look for and remove
  void remove_value(int value);

  // Get value at index
  // @param i: index to access
  // @return: list[i]
  int get(int i);

  // Length of list
  int length;
};

#endif
