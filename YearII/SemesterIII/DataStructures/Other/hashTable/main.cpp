#include <set>
#include <string>
#include <iostream>

using namespace std;

void printhashTable(set<string> hashTable)
{
  cout << "{\n";
  for (auto p : hashTable)
  {
    cout << "  " << p << endl;
  }
  cout << "}\n";
}

int main(void)
{
  set<string> hashTable;

  hashTable.insert("age");
  hashTable.insert("gpa");

  printhashTable(hashTable);

  return 0;
}
