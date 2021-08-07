/**
 * Write a Program that generates all the permutations of a given set of 
 * digits, with or without repetition.
 *
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
#define MAX_DIM 100

using namespace std;

void swap(int &, int &);
void permuteRepetionsAllowed(int *, int);
void permuteWithoutRepetitions(int *, int);
void printPermutationsWithoutRepetitions(int *, int, int, int);
void printPermutationsRepetionsAllowed(int *, int, int *, int, int);

int main()
{
  char ch;
  int arr[MAX_DIM], arrSize;

  cout << "Enter the number of elements: ";
  cin >> arrSize;

  cout << "Enter the elements of the set: ";
  for (int i = 0; i < arrSize; i++)
    cin >> arr[i];

  cout << "Are repetitions allowed? (Y/N) [N]: ";
  cin.ignore();
  cin.get(ch);

  cout << "Possible Permutations:\n";

  switch (ch)
  {
  case 'Y':
    permuteRepetionsAllowed(arr, arrSize);
    break;
  case 'N':
  default:
    permuteWithoutRepetitions(arr, arrSize);
    break;
  }

  return 0;
}

void printPermutationsRepetionsAllowed(
    int *arr, int arrSize, int *data,
    int last, int index)
{
  for (int i = 0; i < arrSize; i++)
  {
    data[index] = arr[i];
    if (index == last)
    {
      cout << "{ ";
      for (int j = 0; j < index + 1; j++)
        cout << data[j] << " ";
      cout << "} ";
    }
    else
      printPermutationsRepetionsAllowed(
          arr, arrSize,
          data, last, index + 1);
  }
}

void permuteRepetionsAllowed(int *arr, int arrSize)
{
  int data[MAX_DIM] = {0};
  printPermutationsRepetionsAllowed(
      arr, arrSize,
      data, arrSize - 1, 0);
  cout << endl;
}

void printPermutationsWithoutRepetitions(
    int *arr, int arrSize,
    int start, int end)
{
  if (start == end)
  {
    cout << "{ ";
    for (int i = 0; i < arrSize; i++)
      cout << arr[i] << " ";
    cout << "} ";
  }
  else
  {
    for (int i = start; i < end + 1; i++)
    {
      swap(arr[start], arr[i]);
      printPermutationsWithoutRepetitions(
          arr, arrSize,
          start + 1, end);
      swap(arr[start], arr[i]);
    }
  }
}

void permuteWithoutRepetitions(int *arr, int arrSize)
{
  printPermutationsWithoutRepetitions(
      arr, arrSize,
      0, arrSize - 1);
  cout << endl;
}

void swap(int &a, int &b)
{
  int t = b;
  b = a;
  a = t;
}
