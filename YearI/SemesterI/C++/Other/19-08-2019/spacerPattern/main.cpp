#include <iostream>

using namespace std;

int main()
{
    for (int x = 20; x >= 1; x--)
    {
        for (int y = x; y >= 1; y--)
            cout << " ";
        cout << x << endl;
    }
    cout << endl;
    return 0;
}