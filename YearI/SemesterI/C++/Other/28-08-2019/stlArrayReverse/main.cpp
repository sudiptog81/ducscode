#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, i = 0;
  int arr[5];

  cout << "Enter 5 integers: ";
  for (auto i = begin(arr); i != end(arr); i++)
    cin >> *i;

  make_heap(begin(arr), end(arr));
  cout << "Heap of Array: ";
  for (auto i = begin(arr); i != end(arr); i++)
    cout << *i << " ";
  cout << endl;

  sort(begin(arr), end(arr));
  cout << "Sorted Array: ";
  for (auto i = begin(arr); i != end(arr); i++)
    cout << *i << " ";
  cout << endl;

  reverse(begin(arr), end(arr));
  cout << "Reverse Sorted Array: ";
  for (auto i = begin(arr); i != end(arr); i++)
    cout << *i << " ";
  cout << endl;

  return 0;
}
