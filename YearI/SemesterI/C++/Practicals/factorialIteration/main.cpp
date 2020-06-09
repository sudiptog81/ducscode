/**
 *  WAP using iterations to calculate Factorial of a 
 *  number
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>

using namespace std;

int main()
{
    int num, factorial = 1;

    // prompt user and accept a number n
    cout << "Enter an integer: ";
    cin >> num;

    // multiply all natural numbers upto n
    // n * n - 1 * n - 2 * ... * 3 * 2 * 1
    for (int i = num; i > 0; i--)
        factorial *= i;

    // print out the factorial
    cout << "Factorial: " << factorial << endl;

    return 0;
}