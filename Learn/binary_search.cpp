#include <iostream>

using namespace std;

// Function prototype
int binary_search(int a[], int e, int l, int r);

int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = 10;    // The array's length
  int index = binary_search(a, 5, 0, n);
  cout << "Index: " << index << endl;
  return 0;
}

/**
 * @brief Binary search.
 *
 * @param a The target array.
 * @param e The target element to find.
 * @param l Left index of finding range.
 * @param r Right index of finding range.
 * @return int Index of the found element, -1 if found nothing.
 */
int binary_search(int a[], int e, int l, int r)
{
  int mid = l + (r - 1) / 2;

  if (l > r) return -1;

  if (a[mid] == e)
  {
    return mid;
  }
  else if (a[mid] > e)
  {
    return binary_search(a, e, l, mid - 1);
  }
  else
  {
    return binary_search(a, e, mid + 1, r);
  }
}