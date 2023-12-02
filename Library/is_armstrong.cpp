#include <iostream>

using namespace std;

// Function prototype
int count_digits(int n);
bool is_armstrong(int n);
int power(int x, int y);

int main()
{
  if (is_armstrong(153))
  {
    cout << "True.";
  }
  else
  {
    cout << "False.";
  }
  return 0;
}

int count_digits(int n)
{
  int digits = 0;
  while (n != 0)
  {
    n = n / 10;
    digits++;
  }
  return digits;
}

bool is_armstrong(int n)
{
  int digits = count_digits(n);
  int sum = 0;
  int temp = n;
  while (temp != 0)
  {
    int digit = temp % 10;
    temp = temp / 10;
    sum += power(digit, digits);
  }
  return sum == n;
}

int power(int x, int y)
{
  int result = 1;
  for (int i = 0; i < y; i++) {
    result *=x;
  }
  return result;
}