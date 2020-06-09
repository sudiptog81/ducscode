/**
 *  WAP to print the triangle of stars as follows:
 * (take number of lines from user) 
 * 
 *     *
 *    ***
 *   *****
 *  *******
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>

using namespace std;

int main()
{
    int n;

    // prompt user and accept n
    cout << "Enter number of rows: ";
    cin >> n;

    cout << endl;

    // outer loop for each line
    for (int i = 1; i <= n; i++)
    {
        // loop for printing spaces
        // no. of spaces = n - i
        for (int j = 1; j <= n - i; j++)
            cout << ' ';

        // loop for prinitng stars
        // no. of stars = 2i - 1 (odd nos.)
        for (int k = 1; k <= 2 * i - 1; k++)
            cout << '*';

        // end line after each iteration
        cout << endl;
    }

    cout << endl;

    return 0;
}
