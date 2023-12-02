#include <iostream>
#include <stack>    // Part of Standard Template Library (STL)

using namespace std;

int main()
{
  stack<int> st;

  if (st.empty())
  {
    cout << "Stack is empty." << endl;
  }

  st.push(8);
  st.push(9);

  cout << "Size: " << st.size() << endl;

  cout << "Top: " << st.top() << endl;    // Does not affect the stack elements.

  int n = st.top();    // Need to get the value before we pop it.
  st.pop();

  cout << "Size: " << st.size() << endl << "Popped value: " << n << endl;

  stack<int> st2;

  st2.swap(st);    // Swap the top element of one stack to another.

  cout << "Size of stack 1: " << st.size() << endl;
  cout << "Size of stack 2: " << st2.size() << endl;

  return 0;
}