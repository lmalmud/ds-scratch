/*
  liked_list_test.cpp
  A simple program to test the basic functionality of linked lists.
*/

// The guards within the header files will prevent
// multiple definitions.
#include "Node.h"
#include "LinkedList.h"

#include <iostream>
#include <cassert>

int main(int argc, char** argv) {
  LinkedList list1 = LinkedList();

  // Ensure list is empty
  list1.print();
  assert(list1.length == 0);

  // Ensure correctness after adding one item (expected [1])
  list1.append(1);
  assert(list1.first() == 1);
  assert(list1.last() == 1);
  assert(list1.length == 1);
  list1.print();

  // Ensure correctness after appending a second item (expected [1, 2])
  list1.append(2);
  assert(list1.first() == 1);
  assert(list1.last() == 2);
  assert(list1.length == 2);
  list1.print();

  // Delete the first item (expected [2])
  list1.remove(0);
  assert(list1.length == 1);
  assert(list1.first() == 2);
  assert(list1.last() == 2);
  list1.print();

  // Append 3, 4, 5 (expected [2, 3, 4, 5])
  list1.append(3);
  assert(list1.last() == 3);
  assert(list1.length == 2);
  list1.append(4);
  assert(list1.last() == 4);
  assert(list1.length == 3);
  list1.append(5);
  assert(list1.last() == 5);
  assert(list1.length == 4);
  list1.print();

  // Delete second item (expected [2, 4, 5])

  // Delete last item (expected [2, 4])
}
