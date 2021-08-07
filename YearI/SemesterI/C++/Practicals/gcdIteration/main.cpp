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
    int a, b, gcd;

    // prompt the user and accept
    // values for A and B
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;

    // swap A and B if A > B
    // to make sure A is smaller
    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    for (int i = 1; i <= a; i++)
    {
        // GCD will be the value of i
        // which will fully divide both
        // A and B completely
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    // print the value of the GCD to stdout
    cout << "GCD of A and B: " << gcd << endl;

    return 0;
}
