#include <map>
#include <string>
#include <iostream>

using namespace std;

void printHashMap(map<string, int> hashMap)
{
  cout << "{\n";
  for (auto p : hashMap)
  {
    cout << "  " << p.first << ": "
         << p.second << endl;
  }
  cout << "}\n";
}

int main(void)
{
  map<string, int> hashMap;

  hashMap["age"] = 21;
  hashMap["gpa"] = 9;

  printHashMap(hashMap);

  return 0;
}
