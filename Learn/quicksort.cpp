#include <iostream>
#include <utility>    // For swaping two array elements function.
#include <cstdlib>
#include <ctime>    // For random selecting the pivot.

using namespace std;

//    How it works?
//
//    The algorithm is going to divide the problem to be solved in to smaller
//    and smaller subproblems.
//
//    Given array:
//
//    6  3  7  5  1  2  4
//
//    Select the last element as the "pivot" (initial pivot)
//
//    6  3  7  5  1  2 [4]
//
//    Now all the elements that are smaller than the pivot will come before the
//    pivot, and all the elements that are larger than the pivot will come after
//    the pivot.
//
//    3  1  2 [4]  6  7  5
//
//    Now do the same algorithm for the portion before and after the pivot.
//

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

    //    How it works?
    //
    //    i
    //    6  3  7  5  1  2  4    pivot_value = 4
    //    j
    //
    //    j++
    //
    //    i
    //    6  3  7  5  1  2  4    pivot_value = 4
    //       j
    //
    //   If j < pivot_value then swap, and i++
    //
    //       i
    //    3  6  7  5  1  2  4    pivot_value = 4
    //       j
    //
    //   j++
    //
    //       i
    //    3  6  7  5  1  2  4    pivot_value = 4
    //          j
    //
    //    [7] is not < pivot_value, so continue j++
    //
    //       i
    //    3  6  7  5  1  2  4    pivot_value = 4
    //             j
    //
    //   [5] still not < pivot_value, continue j++
    //
    //       i
    //    3  6  7  5  1  2  4    pivot_value = 4
    //                j
    //
    //   [1] < pivot_value, then swap them, and i++
    //
    //          i
    //    3  1  7  5  6  2  4    pivot_value = 4
    //                j
    //
    //    Next step
    //
    //             i
    //    3  1  2  5  1  7  4    pivot_value = 4
    //                   j
    //
    //    Now j++ is no longer less than the high index, this is where to stop.
    //
    //    Then swap i with high index
    //
    //             i
    //    3  1  2  4  1  7  5    pivot_value = 4
    //                      j
    //

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot_value)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);

    // Return the index of the swapped pivot, so that we know where to do
    // partitioning.
    return i;
}

void a_display(int a[], int length)
{
    cout << a[0];
    for (int i = 1; i < length; i++)
    {
        cout << " " << a[i];
    }
    cout << endl << endl;
}