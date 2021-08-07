#include <iostream>

using namespace std;

int main()
{
    short marks;

    cout << "Enter Marks: ";
    cin >> marks;

    cout << "Grade: ";

    if (marks >= 90)
        cout << 'A';
    else if (marks >= 80 && marks < 90)
        cout << 'B';
    else if (marks >= 70 && marks < 80)
        cout << 'C';
    else
        cout << 'D';

    cout << endl;

    return 0;
}