/**
 *  Write a program using iteration to:
 *      (a)	Display the Fibonacci Series
 *      (b)	Calculate Factorial of a Number
 *      (c)	Calculate GCD of Two Numbers
 *
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 27 - 09 - 2019
 */

#include <iomanip>
#include <iostream>

using namespace std;

void getch();
void clrscr();

int showMenu();
void calculateGCD();
void displayFibonacci();
void calculateFactorial();

int main(void)
{
    int ch;

    do
    {
        clrscr();

        // show menu and get user choice
        ch = showMenu();

        switch (ch)
        {
        case 1:
            // execute code to display the Fibonacci series
            displayFibonacci();
            break;
        case 2:
            // execute code to calculate Factorial of a number
            calculateFactorial();
            break;
        case 3:
            // execute code to calulcate GCD of two numbers
            calculateGCD();
            break;
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}

// prints the menu and prompts user for choice
int showMenu()
{
    int ch;
    cout << "=== MENU ";
    cout << setw(40) << setfill('=') << "" << endl;
    cout << " (1) Display Fibonacci Series\n";
    cout << " (2) Calculate Factorial of a Number\n";
    cout << " (3) Calculate GCD of Two Numbers\n";
    cout << " (0) Exit the program\n";
    cout << "\nEnter Choice: ";
    cin >> ch;
    return ch;
}

// displays n terms of the Fibonacci series
void displayFibonacci()
{
    int n;
    cout << "\nEnter the number of terms: ";
    cin >> n;

    cout << "First " << n << " terms of the Fibonacci series: ";
    for (int c = 0, next, first = 0, second = 1; c < n; c++)
    {
        if (c <= 1)
            next = c;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        cout << next << " ";
    }
    cout << endl;

    getch();
    return;
}

// calculates Factorial of a positive integer
void calculateFactorial()
{
    int n;
    cout << "\nEnter a positive integer: ";
    cin >> n;

    int product = 1;
    for (int i = n; i > 0; i--)
        product *= i;

    cout << "Factorial of " << n << ": "
         << product << endl;

    getch();
    return;
}

// calculates GCD of two positive integers
void calculateGCD()
{
    int x, y, gcd;

    // prompt user for two integers
    cout << "\nEnter two positive integers: ";
    cin >> x >> y;

    // iterate over all natural numbers upto
    // the smaller number among the two integers
    for (int i = 1; i <= x && i <= y; i++)
    {
        // check if i is a factor of both integers
        if (x % i == 0 && y % i == 0)
            gcd = i;
    }

    // print the greatest common divisor
    cout << "GCD of " << x << " and " << y
         << ": " << gcd << endl;

    getch();
    return;
}

void clrscr()
{
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
}

void getch()
{
    cout << "\nPress Enter to continue... ";
    cin.ignore();
    cin.get();
}
