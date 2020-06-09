#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

void printHashMap(unordered_map<string, int> hashMap)
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
  unordered_map<string, int> hashMap;

  hashMap["age"] = 21;
  hashMap["gpa"] = 9;

  printHashMap(hashMap);

  return 0;
}
