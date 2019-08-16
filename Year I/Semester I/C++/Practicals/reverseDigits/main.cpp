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
    cout << setw(25) << "Enter an integer:";
    cin >> num;

    for (int i = 0; num != 0; num /= 10, i++)
    {
        rem = num % 10;
        rev = rev * 10 + rem;
    }

    cout << setw(25) << "Reversed Integer:" << rev << endl;

    return 0;
}