#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter A: ";
    cin >> a;

    cout << "Enter B: ";
    cin >> b;

    cout << "Enter C: ";
    cin >> c;

    if (a < b)
    {
        if (a < c)
            cout << "a is smallest\n";
    }
    else
    {
        if (a > c)
            cout << "a is largest\n";
        else
            cout << "c is largest\n";
    }

    return 0;
}