#include <iostream>
#include <string>    // For using "string" type

using namespace std;

class BankAccount
{
  private:
    string name;
    int balance;

  public:
    string setName(string n)
    {
      name = n;
    }

    int setBalance(int b)
    {
      balance = b;
    }

    void withdraw(int amount)
    {
      balance = balance - amount;
    }

    void print()
    {
      cout << name << " has " << balance << " dollars" << endl;
    }
};    // Need a semicolon here.

int main()
{
  BankAccount account1;
  account1.setName("Jack");
  account1.setBalance(3000);
  account1.withdraw(100);
  account1.print();
  return 0;
}
