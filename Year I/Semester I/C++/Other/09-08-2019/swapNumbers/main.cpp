#include <iostream>

using namespace std;

int main()
{
    int x, y, temp;

    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;

    cout << "\nX: " << x << "\tY: " << y << "\n\n";

    /**
     * Using a temporary variable
     */
    cout << "Swapping X and Y ...\n\n";

    temp = y;
    y = x;
    x = temp;

    cout << "X: " << x << "\tY: " << y << "\n\n";

    /**
     * Not using a temporary variable
     */
    cout << "Swapping X and Y again ...\n\n";

    x = x + y;
    y = x - y;
    x = x - y;

    cout << "X: " << x << "\tY: " << y << "\n\n";

    return 0;
}