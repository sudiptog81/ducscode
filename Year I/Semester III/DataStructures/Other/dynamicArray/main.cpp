#include "./dynamicArray.hpp"

int main(void)
{
  DynamicArray<int> arr;

  cout << "initial state:\n";
  arr.display();

  for (int i = 1; i <= 8; i++)
    arr.pushBack(i);

  cout << "\nafter pushing entries 1..8:\n";
  arr.display();

  for (int i = 9; i <= 24; i++)
    arr.pushBack(i);

  cout << "\nafter pushing entries 9..24:\n";
  arr.display();

  for (int i = 2; i <= 12; i++)
    arr.remove(i);

  cout << "\nafter removing some entries:\n";
  arr.display();

  return 0;
}