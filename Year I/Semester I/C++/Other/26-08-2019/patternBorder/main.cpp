#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
        cout << '=';
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << '*';
        for (int j = 0; j < 8; j++)
            cout << ' ';
        cout << '*';
        cout << endl;
    }

    for (int i = 0; i < 10; i++)
        cout << '=';
    cout << endl;

    return 0;
}