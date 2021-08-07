#include <iostream>

using namespace std;

int main()
{
    int num, rem, rev = 0;
    cout << "Enter an integer: ";
    cin >> num;

    for (int i = 0, n = num; n != 0; n /= 10, i++)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
    }

    if (rev == num)
        cout << "This is a palindrome :)\n\n";
    else
        cout << "This is not a palindrome :(\n\n";

    return 0;
}