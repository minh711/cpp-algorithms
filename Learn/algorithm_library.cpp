#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[] = {9, 4, 5, 8, 3, 7, 2, 6, 0, 1};   // Length = 10
    int n = 10;    // The array's length

    //    How it works?
    //
    //    sort(array, array + length);
    //
    //    The first argument is the array itself, we say that it decays to a
    //    pointer. So what actually given to the sort function as a first
    //    argument is a pointer to the first element in the array.
    //
    //    The second argument use pointer arithmetic, get the memory address
    //    where we want to stop sorting.
    //

    // sort(a, a + n);    // Sort in ascending order.
    sort(a, a + n, greater<int>());    // Sort in descending order.

    // Displaying the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}