/**
 *  WAP to print the sum and product of digits of an integer  
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int num, rem, sum = 0, product = 1;

    cout << left;
    cout << setw(20) << "Enter an integer:";
    cin >> num;

    for (int i = 0; num != 0; num /= 10, i++)
    {
        rem = num % 10;
        sum += rem;
        product *= rem;
    }

    cout << setw(20) << "Sum of digits:" << sum << endl;
    cout << setw(20) << "Product of digits:" << product << endl;

    return 0;
}
