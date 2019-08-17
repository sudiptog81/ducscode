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

    cout << "Enter an integer: ";
    cin >> num;

    for (int i = num; i > 0; i--)
        factorial *= i;

    cout << "Factorial: " << factorial << endl;

    return 0;
}