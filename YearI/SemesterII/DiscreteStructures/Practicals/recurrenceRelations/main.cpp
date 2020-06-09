/**
 * Write a program to accept an input from the user and
 * graphically represent the values of recurrence relations.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>

using namespace std;

// T(n) = T(n - 1) + n and T(0) = 1
int recurrenceOne(int n)
{
    if (n == 0)
        return 1;
    return recurrenceOne(n - 1) + n;
}

// T(n) = T(n - 1) + n^2 and T(0) = 1
int recurrenceTwo(int n)
{
    if (n == 0)
        return 1;
    return recurrenceTwo(n - 1) + n * n;
}

// T(n) = 2 * T(n / 2) + n and T(1) = 1
int recurrenceThree(int n)
{
    if (n == 1)
        return 1;
    return 2 * recurrenceThree(n / 2) + n;
}

int main()
{
    int n, ch;
    cout << "Choose Recurrence Relation to Evaluate:\n"
         << "  (1) T(n) = T(n - 1) + n and T(0) = 1\n"
         << "  (2) T(n) = T(n - 1) + n^2 and T(0) = 1\n"
         << "  (3) T(n) = 2 * T(n / 2) + n and T(1) = 1\n";
    cout << "Enter Choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "\nEnter Value of n: ";
        cin >> n;
        cout << "\nValues for T(n) = T(n - 1) + n:\n";
        for (int i = n; i >= 0; i--)
        {
            if (i == 0)
                cout << "T(0) = " << recurrenceOne(i)
                     << endl;
            else
                cout << "T(" << i << ") = T(" << (i - 1)
                     << ") + " << i << " = "
                     << recurrenceOne(i)
                     << endl;
        }
        break;
    case 2:
        cout << "\nEnter Value of n: ";
        cin >> n;
        cout << "\nValues for T(n) = T(n - 1) + n^2:\n";
        for (int i = n; i >= 0; i--)
        {
            if (i == 0)
                cout << "T(0) = " << recurrenceTwo(i)
                     << endl;
            else
                cout << "T(" << i << ") = T(" << (i - 1)
                     << ") + " << i * i << " = "
                     << recurrenceTwo(i)
                     << endl;
        }
        break;
    case 3:
        cout << "\nEnter Value of n: ";
        cin >> n;
        cout << "\nValues for T(n) = 2 * T(n / 2) + n:\n";
        for (int i = n; i >= 1; i--)
        {
            if (i == 1)
                cout << "T(1) = " << recurrenceThree(i)
                     << endl;
            else
                cout << "T(" << i << ") = 2 * T(" << i
                     << " / 2) + " << i << " = "
                     << "2 * T(" << (i / 2)
                     << ") + " << i << " = "
                     << recurrenceThree(i)
                     << endl;
        }
        break;
    default:
        cout << "\nInvalid Choice!\n";
        break;
    }
    return 0;
}