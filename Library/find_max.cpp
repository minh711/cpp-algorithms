#include <iostream>

using namespace std;

// Function prototype
int find_max(int a[], int n);

int main() {
    int a[] = {8, 4, 9, 5, 7, 6, 3, 2};
    int max = find_max(a, 8);
    cout << max << endl;
}

/**
 * @brief Find the maximum value.
 *
 * @param a Integer array.
 * @param n Length of the array.
 */
int find_max(int a[], int n) {
  int max;
  max = a[0];
  for (int i = 1; i < n; i++)
  {
    if (a[i] > max)
    {
      max = a[i];
    }
  }
  return max;
}