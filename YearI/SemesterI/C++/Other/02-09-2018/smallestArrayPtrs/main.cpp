#include <iostream>

using namespace std;

int *smallest(int[], int);

int main()
{
    int a[10], *s;

    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; i++)
        cin >> a[i];

    s = smallest(a, 10);

    cout << "Smallest integer: " << *s
         << endl;

    return 0;
}

int *smallest(int a[], int n)
{
    int *psmall, *pwalk, *plast;
    for (psmall = a, pwalk = a + 1, plast = a + (n - 1);
         pwalk <= plast; pwalk++)
        if (*pwalk <= *psmall)
            psmall = pwalk;

    return psmall;
}