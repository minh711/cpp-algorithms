#include <iostream>
#include <utility>    // For swaping two array elements function.
#include <cstdlib>
#include <ctime>    // For random selecting the pivot.

using namespace std;

// Function prototype
void quicksort(int a[], int length);
void quicksort_recursion(int a[], int low, int high);
int partition(int a[], int low, int high);
void a_display(int a[], int length);

int main()
{
    int a[] = {10, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45};
    int length = 13;
    quicksort(a, length);
    a_display(a, 13);
    return 0;
}

void quicksort(int a[], int length)
{
    quicksort_recursion(a, 0, length - 1);
}

/**
 * @brief Quicksort recursion.
 *
 * @param a The target array.
 * @param low Low index.
 * @param high High index.
 */
void quicksort_recursion(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(a, low, high);
        quicksort_recursion(a, low, pivot_index - 1);
        quicksort_recursion(a, pivot_index + 1, high);
    }
}

/**
 * @brief Partitioning.
 *
 * @param a The target array.
 * @param low Low index.
 * @param high High index.
 * @return int Index of the pivot.
 */
int partition(int a[], int low, int high)
{
    int pivot_index = low + rand() % (high - low + 1);
    if (pivot_index != high)
    {
        swap(a[pivot_index], a[high]);
    }
    int pivot_value = a[high];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot_value)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}

void a_display(int a[], int length)
{
    cout << a[0];
    for (int i = 1; i < length; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}