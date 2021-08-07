#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

void printhashTable(unordered_set<string> hashTable)
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
  unordered_set<string> hashTable;

  hashTable.insert("age");
  hashTable.insert("gpa");

  printhashTable(hashTable);

  return 0;
}
