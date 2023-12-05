#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s = "A string with lots of words in it!";
  cout << "Length before: " << s.length() << endl;

  // s.erase(2, 7);
  s.erase(s.begin() + 2, s.begin() + 9);    // The same as above

  cout << "Length after: " << s.length() << endl;
  cout << s << endl;
}