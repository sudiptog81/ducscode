#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int inputs[9];

    cout << setw(15) << left << "Enter 9 Integers" << endl;
    cout << setw(15) << setfill('-') << left << "" << endl;

    for (int i = 0; i < 9; i++)
    {
        cout << "Number " << (i + 1) << ": ";
        cin >> inputs[i];
    }

    for (int i = 0; i < 9; i++)
    {
        int j = i;
        if (++j % 3 == 0)
            cout << inputs[i] << "\n";
        else
            cout << inputs[i] << ", ";
    }

    return 0;
}