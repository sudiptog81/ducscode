/**
 * Write a program to implement Tower of Hanoi using recursion.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>

using namespace std;

void recurse(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "Move Disk 1 from Rod "
             << from << " to Rod " << to
             << endl;
        return;
    }
    recurse(n - 1, from, aux, to);
    cout << "Move Disk " << n << " from Rod "
         << from << " to Rod " << to
         << endl;
    recurse(n - 1, aux, to, from);
}

int main()
{
    int n;
    cout << "Enter Number of Disks: ";
    cin >> n;
    char arr[3];
    cout << "Enter Label of Source Rod: ";
    cin >> arr[0];
    cout << "Enter Label of Destination Rod: ";
    cin >> arr[1];
    cout << "Enter Label of Auxiliary Rod: ";
    cin >> arr[2];
    cout << "Possible Steps:\n";
    recurse(n, arr[0], arr[2], arr[1]);
    return 0;
}
