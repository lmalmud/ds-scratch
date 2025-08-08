#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

class DynamicArray {
 private:
  int[] a;

 public:
  int length;

  // Adds an item to the end of the list
  // @param value: the value to be adde
  void append(int value);
}

#endif
