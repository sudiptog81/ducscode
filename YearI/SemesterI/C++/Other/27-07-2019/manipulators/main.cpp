#include <iostream>
#include <iomanip>

using namespace std;

void manipGeneral()
{
    cout << setw(10) << 123 << endl;                 // prints seven spaces before 123
    cout << setw(10) << setfill('*') << 123 << endl; // fills spaces with '*'
}

void manipFloat()
{
    cout << fixed << 1.2345 << endl;                        // precision defaults to 6
    cout << setprecision(2) << 1.2345 << endl;              // precision set to 2
    cout << setprecision(0) << 1.2345 << endl;              // only integral part
    cout << setprecision(0) << showpoint << 1.2345 << endl; // shows the decimal point
}

int main()
{
    manipGeneral();
    manipFloat();
    cout << "\nExiting...\n";
    return 0;
}