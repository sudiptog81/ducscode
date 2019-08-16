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

    cout << "Enter an integer: ";
    cin >> num;

    cout << "Factors: ";

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            cout << i << " ";
    }

    cout << endl;

    return 0;
}
