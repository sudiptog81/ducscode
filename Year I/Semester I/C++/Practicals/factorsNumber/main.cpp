/**
 *  WAP to compute the factors of a given integer
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>

using namespace std;

int main()
{
    int num, factor;

    // prompt user and accept num
    cout << "Enter an integer: ";
    cin >> num;

    cout << "Factors: ";

    // iterating over the interval [1, num],
    //   integral values in the range that divide
    //   num completely are printed to stdout
    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            cout << i << " ";

    cout << endl;

    return 0;
}
