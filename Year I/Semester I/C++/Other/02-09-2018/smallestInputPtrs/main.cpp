#include <iostream>

using namespace std;

int *smallest(int *, int *);

int main()
{
    int a, b, *s;
    cout << "Enter 2 integers: ";
    cin >> a >> b;
    s = smallest(&a, &b);
    cout << "Smallest integer: " << *s;
    return 0;
}

int *smallest(int *p, int *q)
{
    return (*p > *q ? q : p);
}