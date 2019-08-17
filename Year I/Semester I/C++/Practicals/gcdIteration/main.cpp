/**
 *  WAP using iterations to find the GCD of 2 numbers
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>

using namespace std;

int main()
{
    int a, b, least, gcd;

    cout << "Enter A: ";
    cin >> a;

    cout << "Enter B: ";
    cin >> b;

    if (a > b)
        least = b;
    if (b > a)
        least = a;

    for (int i = 1; i <= least; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    cout << "GCD: " << gcd << endl;

    return 0;
}
