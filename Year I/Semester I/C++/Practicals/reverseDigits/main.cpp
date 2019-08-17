/**
 *  WAP to reverse of digits of an integer  
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int num, rem, rev = 0;

    cout << left;

    // prompt user and accept an integer num
    cout << setw(25) << "Enter an integer:";
    cin >> num;

    // repeat as long as num != 0
    for (int i = 0; num != 0; num /= 10, i++)
    {
        // derive the last digit of num
        rem = num % 10;

        // adjust positional value, add
        // the last digit of num to rev
        rev = rev * 10 + rem;
    }

    // print the rerversed integer
    cout << setw(25) << "Reversed Integer:" << rev << endl;

    return 0;
}