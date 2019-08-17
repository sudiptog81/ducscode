/**
 *  WAP using iterations to display the Fibonacci 
 *  series
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>

using namespace std;

int main()
{
    int num, sum = 0, n_1 = 0, n_2 = 1;

    cout << "Enter the number of terms: ";
    cin >> num;

    cout << "Fibonacci Series: ";
    cout << n_1 << " " << n_2 << " ";

    for (int i = 2; i < num; n_1 = n_2, n_2 = sum, i++)
    {
        sum = n_1 + n_2;
        cout << sum << " ";
    }

    cout << endl;

    return 0;
}