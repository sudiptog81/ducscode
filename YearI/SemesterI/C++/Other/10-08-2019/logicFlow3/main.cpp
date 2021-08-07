#include <iostream>

using namespace std;

int main()
{
    int x, y, z;

    cout << "Enter X: ";
    cin >> x;

    cout << "Enter Y: ";
    cin >> y;

    cout << "Enter Z: ";
    cin >> z;

    switch (x)
    {
    case 1:
        y = y * x;
        z = z + 1;
        break;
    case 2:
        z = z + 2;
        break;
    case 3:
        y = y * 5;
        break;
    case 4:
        z = z - 1;
        break;
    }

    cout << "X: " << x << "\nY: " << y << "\nZ: " << z << endl;

    return 0;
}
