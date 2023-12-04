#include <iostream>

int main()
{
  int *a;            // The dynamic array.
  a = new int[3];    // Assign a size.
  delete[] a;        // Delete the array.
  a = new int[5];    // Assign new size.

  return 0;
}