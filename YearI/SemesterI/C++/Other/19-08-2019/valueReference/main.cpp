#include <iostream>

using namespace std;

void swapValue(int, int);
void swapReference(int &, int &);
void changeVariableByValue(int, int);
void changeVariableByReference(int &, int &);

int main()
{
    int a, b;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;
    cout << endl;
    cout << "Initial Values:\n---------------\n"
         << "a: " << a << "\tb: " << b << endl;
    cout << endl;
    cout << "Swap by Value:\n---------------\n";
    cout << "Before Call:\n"
         << "a: " << a << "\tb: " << b << endl;
    swapValue(a, b);
    cout << "After Call:\n"
         << "a: " << a << "\tb: " << b << endl;
    cout << endl;
    cout << "Swap by Reference:\n---------------\n";
    cout << "Before Call:\n"
         << "a: " << a << "\tb: " << b << endl;
    swapReference(a, b);
    cout << "After Call:\n"
         << "a: " << a << "\tb: " << b << endl;
    cout << endl;
    cout << "Change by Value:\n---------------\n";
    cout << "Before Call:\n"
         << "a: " << a << "\tb: " << b << endl;
    changeVariableByValue(a, b);
    cout << "After Call:\n"
         << "a: " << a << "\tb: " << b << endl;
    cout << endl;
    cout << "Change by Reference:\n---------------\n";
    cout << "Before Call:\n"
         << "a: " << a << "\tb: " << b << endl;
    changeVariableByReference(a, b);
    cout << "After Call:\n"
         << "a: " << a << "\tb: " << b << endl;
    cout << endl;
    return 0;
}

void swapValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside Function:\n"
         << "a: " << a << "\tb: " << b << endl;
    return;
}

void swapReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside Function:\n"
         << "a: " << a << "\tb: " << b << endl;
    return;
}

void changeVariableByValue(int a, int b)
{
    a = 1;
    b = 2;
    cout << "Inside Function:\n"
         << "a: " << a << "\tb: " << b << endl;
    return;
}

void changeVariableByReference(int &a, int &b)
{
    a = 1;
    b = 2;
    cout << "Inside Function:\n"
         << "a: " << a << "\tb: " << b << endl;
    return;
}