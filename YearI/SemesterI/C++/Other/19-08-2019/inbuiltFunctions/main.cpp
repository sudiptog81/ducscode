#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    cout << "Absolute of -3: " << abs(-3) << "\n";
    cout << "Absolute of -99931293129313: " << labs(-99931293129313L) << "\n";
    cout << "Absolute of -342.15: " << fabs(-342.15f) << "\n";
    cout << "Ceiling of 0.1: " << ceil(0.1) << "\n";
    cout << "Floor of -0.1: " << floor(-0.1) << "\n";
    cout << "2 to the power 5: " << pow(2, 5) << "\n";
    cout << "0 to the power -5: " << pow(0, -5) << "\n";      // infinity
    cout << "-2 to the power 5.1: " << pow(-2, 5.1f) << "\n"; // nan

    cout << "\n";

    return 0;
}