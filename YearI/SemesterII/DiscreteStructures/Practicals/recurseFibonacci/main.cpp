/**
 * Write a program to generate the Fibonacci Series using recursion.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>

using namespace std;

int recurse(int n)
{
    if (n <= 1)
        return n;
    return recurse(n - 1) + recurse(n - 2);
}

int main()
{
    int n;
    cout << "Enter Number of Terms: ";
    cin >> n;
    cout << "Fibonacci Sequence: ";
    for (int i = 0; i < n; i++)
        cout << recurse(i) << " ";
    return 0;
}