/**
 *  WAP to print the triangle of stars as follows:
 * (take number of lines from user) 
 * 
 *  *
 *  ***
 *  *****
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

    cout << "Enter number of rows: ";
    cin >> n;

    cout << endl;

    for (int i = 1; i <= 2 * n; i = i + 2)
    {
        for (int j = 0; j < i; j++)
            cout << '*';
        cout << endl;
    }

    cout << endl;

    return 0;
}
