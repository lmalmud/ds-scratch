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
  // O(1)
  LinkedList();
  
  // Add a value to the end of the list.
  // @param value: integer to append
  // O(1)
  void append(int value);

  // Delete item at given index
  // @param i: index to remove from
  // @throws runtime_error: removal from empty list, out of bounds
  // O(n)
  void remove(int i);

  // Output the length and content
  // of list to the screen.
  // O(n)
  void print();

  // Output the first item in the list
  // O(1)
  int first();

  // Output the last item in the list
  // O(1)
  int last();

  // Look for an item with the given value
  // @param value: target value within list
  // @return: true if value is present and false otherwise
  // O(n)
  bool find(int value);

  // Remove a particular value
  // @param value: value to look for and remove
  // O(n)
  void remove_value(int value);

  // Get value at index
  // @param i: index to access
  // @return: list[i]
  // O(n)
  int get(int i);

  // Length of list
  int length;
};

#endif
