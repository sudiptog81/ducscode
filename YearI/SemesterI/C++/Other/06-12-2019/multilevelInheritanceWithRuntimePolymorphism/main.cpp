#include <string>
#include <iostream>

using namespace std;

class Person
{
protected:
  string Name;
  long Code;
public:
  virtual void getInfo ()
  {
    cout << "Enter Name: ";
    cin.sync();
    getline(cin, Name);
    cout << "Enter Code: ";
    cin >> Code;
  }
  virtual void putInfo ()
  {
    cout << "\nNAME:\t" << Name << "\nCODE:\t" << Code;
  }
};

class Account : public Person
{
protected:
  int Pay;
public:
  virtual void getInfo ()
  {
    cout << "Enter Pay: ";
    cin >> Pay;
  }
  virtual void putInfo ()
  {
    cout << "\nPAY:\t" << Pay << '\n';
  }
};

class Employee : public Account
{
public:
  virtual void getInfo ()
  {
    Person::getInfo ();
    Account::getInfo ();
  }
  virtual void putInfo ()
  {
    Person::putInfo ();
    Account::putInfo ();
  }
};

int main ()
{
  Person *ptr = new Person ();
  ptr->getInfo ();
  ptr->putInfo ();

  cout << endl << endl;

  ptr = new Employee ();
  ptr->getInfo ();
  ptr->putInfo ();

  delete ptr;
  return 0;
}
