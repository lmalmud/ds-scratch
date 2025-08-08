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
  list1.print();
  assert(list1.length == 0);
  list1.append(1);
  list1.print();
}
