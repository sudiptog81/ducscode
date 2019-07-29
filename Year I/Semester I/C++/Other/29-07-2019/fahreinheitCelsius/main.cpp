#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double f;
    cout << "Enter temperature in Fahreinheit: ";
    cin >> f;

    cout << endl;

    cout << setw(25) << left << "Fahreinheit Temperature:";
    cout << setw(5) << right << setprecision(3) << showpoint << f << endl;

    cout << setw(25) << left << "Celsius Temperature:";
    cout << setw(5) << right << setprecision(3) << showpoint << ((5.0 / 9.0) * (f - 32.0)) << endl;

    return 0;
}