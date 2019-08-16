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
    float sum = 0, denom = 1.0;

    cout << "Enter an integer n upto which the sum is desired: ";
    cin >> n;

    for (int i = 1; i <= n; denom++, i++)
    {
        sum = sum + (1 / denom);
    }

    cout << "Sum of the series upto n terms: " << sum << endl;

    return 0;
}