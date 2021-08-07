/**
 *  Write a function to find whether a given no. is 
 *  Prime or not. Use the same to generate prime
 *  numbers less than 100.
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 06 - 09 - 2019
 */

#include <iostream>

using namespace std;

bool checkPrime(int);

int main()
{
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    if (checkPrime(n))
        cout << n << " is a prime number.";
    else
        cout << n << " is not a prime number.";

    cout << endl
         << endl;

    cout << "Prime Numbers upto 100\n";
    cout << "----------------------\n";
    for (int i = 2; i < 100; i++)
        if (checkPrime(i))
            cout << i << " ";

    return 0;
}

bool checkPrime(int n)
{
    if (n <= 1)
        return false;
    else
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
    return true;
}