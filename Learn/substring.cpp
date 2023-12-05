#include <iostream>
#include <string>

int main() {
  std::string str = "Hello, World!";

  // Extract substring starting from index 7 (inclusive) with a length of 5
  // characters
  std::string sub = str.substr(7, 5); // "World"

  std::cout << "Original string: " << str << std::endl;
  std::cout << "Substring: " << sub << std::endl;

  return 0;
}