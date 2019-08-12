#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int choice, num, rem, sum, product;

    cout << left;

    cout << "Choice - (1) for Loop (2) do...while loop: ";
    cin >> choice;

    cout << setw(20) << "Enter a number: ";
    cin >> num;

    if (choice == 2)
    {
        rem = 0, sum = 0, product = 1;
        do
        {
            rem = num % 10;
            sum += rem;
            product *= rem;
            num /= 10;
        } while (num != 0);
    }
    else if (choice == 1)
    {
        for (num, rem = 0, sum = 0, product = 1; num != 0; num /= 10)
        {
            rem = num % 10;
            sum += rem;
            product *= rem;
        }
    }

    cout << setw(20) << "Sum of digits:";
    cout << setw(8) << sum;
    cout << endl;
    cout << setw(20) << "Product of digits:";
    cout << setw(8) << product;
    cout << endl;

    return 0;
}