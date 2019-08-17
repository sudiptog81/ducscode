/**
 *  WAP to compute the sum upto the n terms of the
 *  following series:
 *        S = 1 - 2 + 3 - 4 + 5 - 6 + ...
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0;

    // prompt user and accept n which is the upper limit of the sum
    cout << "Enter an integer n upto which the sum is desired: ";
    cin >> n;

    // calculate sum of the series
    for (int i = 1; i <= n; i++)
    {
        // if i is even (where i belongs to [1,n]),
        //      subtract i from the sum
        if (i % 2 == 0)
            sum -= i;

        // if i is odd (where i belongs to [1,n]),
        //      add i to the sum
        else
            sum += i;
    }

    // print the sum of the series upto n terms
    cout << "Sum of the series upto n terms: " << sum << endl;

    return 0;
}