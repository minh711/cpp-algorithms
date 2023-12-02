#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> qu;

    qu.size();     // Return the size of the queue.
    qu.empty();    // Return boolean if the queue is empty or not.

    qu.push(8);
    qu.push(9);

    qu.front();    // Access the first element.
    qu.back();     // Access the last element.
    qu.pop();      // Remove the first element.

    return 0;
}