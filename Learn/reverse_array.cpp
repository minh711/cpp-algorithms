#include <iostream>

using namespace std;

// Function prototype
void a_reverse(int a[], int n);
void a_display(int a[], int n);

int main()
{
    int a[] = {8, 4, 2, 5, 2, 6, 3, 2};
    int n = 8;
    a_reverse(a, n);
    a_display(a, 8);
    return 0;
}

/**
 * @brief Reversing an array.
 *
 * @param a The target array.
 * @param n The array's length.
 */
void a_reverse(int a[], int n)
{
    int temp = 0;    // For swapping
    for (int i = 0; i < (n / 2); i++)
    {
        temp = a[i];
        a[i] = a[n - i - 1];    // -1 since the index start from 0
        a[n - i - 1] = temp;
    }
}

/**
 * @brief Display for an array.
 *
 * @param a Integer array.
 * @param n Length of the array.
 */
void a_display(int a[], int n)
{
    cout << a[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}