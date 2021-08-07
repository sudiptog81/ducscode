#include <iostream>

using namespace std;

int main()
{
    int choice;
    float marks;

    cout << "Choice - (1) if...else (2) switch: ";
    cin >> choice;

    cout << "Enter your marks out of 100: ";
    cin >> marks;

    cout << "Grade: ";

    if (choice == 2)
    {
        marks /= 10;
        switch ((int)marks)
        {
        case 10:
        case 9:
            cout << "A";
            break;
        case 8:
            cout << "B";
            break;
        case 7:
            cout << "C";
            break;
        case 6:
            cout << "D";
            break;
        default:
            cout << "E";
        }
    }
    else if (choice == 1)
    {
        if (marks <= 100 && marks >= 90)
            cout << "A";
        else if (marks >= 80)
            cout << "B";
        else if (marks >= 70)
            cout << "C";
        else if (marks >= 60)
            cout << "D";
        else
            cout << "E";
    }

    cout << endl;

    return 0;
}
