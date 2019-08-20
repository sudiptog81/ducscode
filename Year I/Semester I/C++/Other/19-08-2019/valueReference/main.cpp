#include <iostream>

using namespace std;

void swapValue(int a, int b);
void swapReference(int &a, int &b);

int main()
{
    int a, b;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;

    cout << "a: " << a << "\tb: " << b << endl;
    swapValue(a, b);
    swapReference(a, b);

    return 0;
}

void swapValue(int a, int b)
{
    cout << "By Value:\n";
    int temp = a;
    a = b;
    b = temp;
    cout << "a: " << a << "\tb: " << b << endl;
    return;
}

void swapReference(int &a, int &b)
{
    cout << "By Reference:\n";
    int temp = a;
    a = b;
    b = temp;
    cout << "a: " << a << "\tb: " << b << endl;
    return;
}