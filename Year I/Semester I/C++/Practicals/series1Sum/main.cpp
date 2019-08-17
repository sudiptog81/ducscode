/**
 *  WAP to compute the sum upto the n terms of the
 *  following series:
 *        S = 1 + 1/2 + 1/3 + 1/4 + 1/5 + ...
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>

using namespace std;

int main()
{
    int n;
    float sum = 0;

    // prompt user and accept n which is the upper limit of the sum
    cout << "Enter an integer n upto which the sum is desired: ";
    cin >> n;

    // calculate sum of the series
    for (int i = 1; i <= n; i++)
    {
        sum += ((float)1 / (float)i);
    }

    // print the sum of the series upto n terms to stdout
    cout << "Sum of the series upto n terms: " << sum << endl;

    return 0;
}