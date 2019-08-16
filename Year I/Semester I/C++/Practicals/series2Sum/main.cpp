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

    cout << "Enter an integer n upto which the sum is desired: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            sum -= i;
        else
            sum += i;
    }

    cout << "Sum of the series upto n terms: " << sum << endl;

    return 0;
}