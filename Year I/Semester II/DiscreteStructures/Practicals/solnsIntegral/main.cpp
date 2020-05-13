/**
 * For any number n, write a program to list all the solutions of 
 * the equation x1 + x2 + x3 + … + xn = C, where C is a constant 
 * (C <= 10) and x1, x2, x3, …, xn are nonnegative integers using 
 * brute force strategy.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
#define MAX_DIM 100

using namespace std;

void permute(int *arr, int arrSize,
             int *data, int last, int index,
             int C, int &counter)
{
  for (int i = 0; i < arrSize; i++)
  {
    data[index] = arr[i];
    if (index == last)
    {
      int sum = 0;
      for (int j = 0; j < index + 1; j++)
        sum += data[j];
      if (sum == C)
      {
        cout << "[ ";
        for (int j = 0; j < index + 1; j++)
          cout << data[j] << " ";
        cout << "] ";
        counter++;
      }
    }
    else
      permute(arr, arrSize, data, last, index + 1, C, counter);
  }
}

int main()
{
  int n, C, counter = 0, arrSize = 11;
  int arr[11], data[MAX_DIM] = {0};
  cout << "Finding solutions to x1 + x2 + ..."
       << " + xn = C\n";
  cout << "Enter the number of terms (n): ";
  cin >> n;
  for (int i = 0; i <= 10; i++)
    arr[i] = i;
  cout << "Enter the sum constant (C <= 10): ";
  cin >> C;
  cout << "Possible Non-negative Integral Solutions [ ";
  for (int i = 0; i < n; i++)
    cout << "x" << i + 1 << " ";
  cout << "] :" << endl;
  permute(arr, arrSize, data, n - 1, 0, C, counter);
  cout << "\nFound " << counter << " Solutions\n";
  return 0;
}