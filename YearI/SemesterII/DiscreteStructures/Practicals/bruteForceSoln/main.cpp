/**
 * For any number n, write a program to list all the solutions of the equation 
 * x1 + x2 + x3 + … + xn = C, where C is a constant (C <= 10) and x1, x2, x3, 
 * …, xn are nonnegative integers using brute force strategy.
 *
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
using namespace std;

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

int main()
{
    int n, C;

    cout << "Enter value of n: ";
    cin >> n;
    cout << "Enter value of C: ";
    cin >> C;

    // No. of non-negative integral solutions: C(n + C - 1 , C)
    cout << "Number of all non-negative integral solutions: "
         << combination(n + C - 1, C);

    return 0;
}
