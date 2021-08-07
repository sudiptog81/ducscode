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

    // prompt user and accept num
    cout << setw(20) << "Enter an integer:";
    cin >> num;

    // iterate over digits of num by dividing
    // num by 10 after each iteration to get
    // the integral quotient in num
    for (int i = 0; num != 0; num /= 10, i++)
    {
        // derive the last digit of num
        rem = num % 10;

        // add the lhe last digit to sum
        sum += rem;

        // multiply the last digit with the product
        product *= rem;
    }

    // print the sum and product of digits
    cout << setw(20) << "Sum of digits:" << sum << endl;
    cout << setw(20) << "Product of digits:" << product << endl;

    return 0;
}
