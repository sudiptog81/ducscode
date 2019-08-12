#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int choice, num, rem, rev;

    cout << left;

    cout << "Choice - (1) for Loop (2) do...while Loop: ";
    cin >> choice;

    cout << setw(20) << "Enter a number:";
    cin >> num;

    if (choice == 2)
    {
        rem = 0, rev = 0;
        do
        {
            rem = num % 10;
            rev = rev * 10 + rem;
            num /= 10;
        } while (num != 0);
    }
    else if (choice == 1)
    {
        for (num, rem = 0, rev = 0; num != 0; num /= 10)
        {
            rem = num % 10;
            rev = rev * 10 + rem;
        }
    }

    cout << setw(20) << "Reversed Number:";
    cout << rev << endl;

    return 0;
}