#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter number of rows upto middle of the pattern: ";
    cin >> n;

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << ' ';
        for (int k = 1; k <= 2 * i - 1; k++)
            cout << '*';
        cout << endl;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = n - i; j >= 1; j--)
            cout << ' ';
        for (int k = 2 * i - 1; k >= 1; k--)
            cout << '*';
        cout << endl;
    }

    cout << endl;

    return 0;
}