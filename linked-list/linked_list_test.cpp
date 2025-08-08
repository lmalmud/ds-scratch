/*
  liked_list_test.cpp
  A simple program to test the basic functionality of linked lists.

  g++ LinkedList.cpp Node.cpp linked_list_test.cpp
*/

// The guards within the header files will prevent
// multiple definitions.
#include "Node.h"
#include "LinkedList.h"

#include <iostream>
#include <cassert>

#define assert(condition) { if(!(condition)){ std::cerr << "ASSERT FAILED: " << #condition << " @ " << __FILE__ << " (" << __LINE__ << ")" << std::endl; }} //else { std::cerr << "ASSERT PASSED: " << #condition << std::endl;} }

int main(int argc, char** argv) {
  LinkedList list1 = LinkedList();

  // Ensure list is empty
  list1.print();
  assert(list1.length == 0);

  // Error thrown when trying to remove from empty list
  bool removeError = false;
  try {
    list1.remove(0);
  } catch (const std::runtime_error& e) {
    removeError = true;
  }
  assert(removeError);

  // Ensure correctness after adding one item (expected [1])
  list1.append(1);
  assert(list1.first() == 1);
  assert(list1.last() == 1);
  assert(list1.length == 1);
  assert(list1.get(0) == 1);
  list1.print();

  // Ensure correctness after appending a second item (expected [1, 2])
  list1.append(2);
  assert(list1.first() == 1);
  assert(list1.last() == 2);
  assert(list1.length == 2);
  assert(list1.get(0) == 1);
  assert(list1.get(1) == 2);
  list1.print();

  // Delete the first item (expected [2])
  list1.remove(0);
  assert(list1.length == 1);
  assert(list1.first() == 2);
  assert(list1.last() == 2);
  assert(list1.get(0) == 2);
  list1.print();

  // Append 3, 4, 5 (expected [2, 3, 4, 5])
  list1.append(3);
  assert(list1.last() == 3);
  assert(list1.length == 2);
  assert(list1.get(0) == 2);
  assert(list1.get(1) == 3);
  list1.append(4);
  assert(list1.last() == 4);
  assert(list1.length == 3);
  assert(list1.get(2) == 4);
  list1.append(5);
  assert(list1.last() == 5);
  assert(list1.length == 4);
  assert(list1.get(3) == 5);
  list1.print();

  // Delete second item (expected [2, 4, 5])
  list1.remove(1);
  assert(list1.length == 3);
  assert(list1.first() == 2);
  assert(list1.last() == 5);
  list1.print();

  // Delete last item (expected [2, 4])
  list1.remove(2);
  assert(list1.get(0) == 2);
  assert(list1.get(1) == 4);
  assert(list1.length == 2);
  assert(list1.first() == 2);
  assert(list1.last() == 4);
  list1.print();

  // Exception thrown when trying to access out of range
  bool catchesRemove = false;
  try {
    list1.remove(3);
  } catch (const std::runtime_error& e) {
    catchesRemove = true;
  }
  assert(catchesRemove);

  // Able to find value that is present
  assert(list1.find(2));
  assert(list1.find(4));

  // Able to detect when value is *not* present
  assert(!list1.find(3));

  // Exception throw when trying to access nonexistent element
  bool catchesNonexistent = false;
  try {
    list1.remove_value(7);
  } catch (const std::runtime_error& e) {
    catchesNonexistent = true;
  }
  assert(catchesNonexistent);

  // Remove the 2 in the first position: expects [4]
  list1.remove_value(2);
  assert(list1.length == 1);
  assert(list1.first() == 4);
  assert(list1.last() == 4);

  // Add 5, 6 and then remove the 5. Expects [4, 6]
  list1.append(5);
  list1.append(6);
  list1.remove_value(5);
  assert(list1.length == 2);
  assert(list1.get(0) == 4);
  assert(list1.get(1) == 6);
  assert(list1.first() == 4);
  assert(list1.last() == 6);
}
