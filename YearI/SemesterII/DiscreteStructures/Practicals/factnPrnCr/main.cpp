/**
 * Write a Program to calculate Permutation and Combination for an input value
 * n and r using recursive formula of nCr and nPr.
 *
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>

using namespace std;

/**
 * Calculates P(n, r) using the recursive definition
 * => P(n, r) = P(n - 1, r) + r * P(n - 1, r - 1)
 */
int permutation(int n, int r)
{
  if (r == 0)
    return 1;
  if (r > n)
    return 0;
  return permutation(n - 1, r) + r * permutation(n - 1, r - 1);
}

/**
 * Calculates C(n, r) using the recursive definition
 * => C(n, r) = C(n - 1, r) + C(n - 1, r - 1)
 */
int combination(int n, int r)
{
  if (r == 0 || r == n)
    return 1;
  return combination(n - 1, r) + combination(n - 1, r - 1);
}

/**
 * Handles Application Logic
 */
void handleMenu()
{
  int choice;

  cout << "== Recursive Calculator ==\n";
  cout << "  (1) Calculate P(n, r)\n";
  cout << "  (2) Calculate C(n, r)\n";
  cout << "Enter Choice: ";
  cin >> choice;
  cout << endl;

  int n;
  cout << "Enter value of n: ";
  cin >> n;

  int r;
  cout << "Enter value of r: ";
  cin >> r;

  switch (choice)
  {
  case 1:
    cout << "P(" << n << ", " << r << ") = "
         << permutation(n, r);
    break;
  case 2:
    cout << "C(" << n << ", " << r << ") = "
         << combination(n, r);
    break;
  default:
    break;
  }
}

/**
 * Driver Code
 */
int main(int argc, char *argv[])
{
  handleMenu();
  return 0;
}
