#include <iostream>

using namespace std;

void swapValue(int a, int b);
void swapReference(int &a, int &b);
void changeVariableByValue(int a, int b);
void changeVariableByReference(int &a, int &b);

int main()
{
    int a, b;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;

    cout << "Initial Values:\n"
         << "a: " << a << "\tb: " << b << endl;
    swapValue(a, b);
    cout << "Swap by Value:\n"
         << "a: " << a << "\tb: " << b << endl;
    swapReference(a, b);
    cout << "Swap by Reference:\n"
         << "a: " << a << "\tb: " << b << endl;
    changeVariableByValue(a, b);
    cout << "Changed by Value:\n"
         << "a: " << a << "\tb: " << b << endl;
    changeVariableByReference(a, b);
    cout << "Changed by Reference:\n"
         << "a: " << a << "\tb: " << b << endl;

    return 0;
}

void swapValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

void swapReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

void changeVariableByValue(int a, int b)
{
    a = 1;
    b = 2;
    return;
}

void changeVariableByReference(int &a, int &b)
{
    a = 1;
    b = 4;
    return;
}