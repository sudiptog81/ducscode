#include <iostream>
#include <cmath>

using namespace std;

void populateArray(int *, int);
void raiseArray(int *, int, int);
void printArray(const int *, int);

int main()
{
  int n, exp;

  cout << "Enter size of the array: ";
  cin >> n;

  cout << "Enter exponent: ";
  cin >> exp;

  int *arr = new int[n];
  cout << "Array of size " << n << " created at "
       << arr << endl;

  populateArray(arr, n);
  raiseArray(arr, n, exp);
  printArray(arr, n);

  cout << endl;
  return 0;
}

void populateArray(int arr[], int size)
{
  cout << "Enter elements of the array: ";
  for (int i = 0; i < size; i++)
    cin >> arr[i];
  return;
}

void raiseArray(int arr[], int size, int exp)
{
  for (int i = 0; i < size; i++)
    arr[i] = pow(arr[i], exp);
  return;
}

void printArray(const int arr[], int size)
{
  cout << "Elements of the array: ";
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  return;
}