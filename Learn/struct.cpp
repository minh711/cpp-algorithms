#include <iostream>
#include <cstring>

using namespace std;

struct Student
{
  char name[50];
  char id[10];
  int age;
  int grades[5];
};    // Need a semicolon here.

struct Point
{
  int x;
  int y;
} p1, p2, p3;    // You can declare some structs right here.

// Can use typedef like this
//
// typedef struct
// {
//   int x;
//   int y;
// } Point;
//

int main()
{
  struct Student kevin;

  // strcpy is copy string function. Copies the C string pointed by source into
  // the array pointed by destination, including the terminating null character
  // (and stopping at that point).
  //
  // To avoid overflows, the size of the array pointed by destination shall be
  // long enough to contain the same C string as source (including the
  // terminating null character), and should not overlap in memory with source.
  //
  strcpy(kevin.name, "Kevin");
  kevin.age = 20;
  cout << kevin.name << endl;
  cout << kevin.age << endl;

  Point p1;
  Point p2;

  p1.x = 10;
  p1.y = 20;
  p2 = {3, 5};    // Can assign values like this too.

  // This is possible in C but C++ not supporting it.
  //
  // Point p3 =
  // {
  //   .y = 8,
  //   .x = 2
  // };
  //

  cout << "p1(" << p1.x << ", " << p1.y << ")" << endl;
  cout << "p2(" << p2.x << ", " << p2.y << ")" << endl;

  return 0;
}
