#include <iostream>

using namespace std;

int main()
{
    char temp;
    int x, y, z;

    cout << "Enter X: ";
    cin >> x;

    cout << "Enter Y: ";
    cin >> y;

    if (x > 0)
    {
        if (y > 0)
        {
            z = y;
        }
        else
        {
            z = x;
            y = x + 1;
        }
        z = z + 1;
    }
    else
    {
        y = x - 1;
        z = 2 * x;
    }

    cout << "X: " << x << "\nY: " << y << "\nZ: " << z << endl;

    return 0;
}
