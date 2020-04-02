/**
 * For any number n, write a program to list all the solutions of 
 * the equation x1 + x2 + x3 + … + xn = C, where C is a constant 
 * (C <= 10) and x1, x2, x3, …, xn are nonnegative integers using 
 * brute force strategy.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */
#include <iostream>
using namespace std;
int getSolutionsCount(int n, int k)
{
    // Initialize Accumulator
    int total = 0;

    // Base Case
    if (n == 1 && k >= 0)
        return 1;

    // Iterate k times
    for (int i = 0; i <= k; i++)
        // Accumulate Count of Solutions
        total += getSolutionsCount(n - 1, k - i);

    // Return Accumulator
    return total;
}

int main()
{
    cout << "Finding solutions to x1 + x2 + ..."
         << " + xn = C" << endl;
    int n, c;
    cout << "Enter the number of terms (n): ";
    cin >> n;
    cout << "Enter the sum constant (C <= 10): ";
    cin >> c;
    cout << "Total Non-negative Integral Solutions: "
         << getSolutionsCount(n, c) << endl;
    return 0;
}