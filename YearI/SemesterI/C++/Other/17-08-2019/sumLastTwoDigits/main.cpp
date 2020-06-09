#include <iostream>

using namespace std;

int getFirstDigit(int);
int getSecondDigit(int);
int sumOfLastTwoDigits(int);

int main()
{
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    cout << "Sum of last 2 digits: "
         << sumOfLastTwoDigits(num);

    cout << endl;

    return 0;
}

int getFirstDigit(int x)
{
    return x % 10;
}

int getSecondDigit(int x)
{
    return (x / 10) % 10;
}

int sumOfLastTwoDigits(int x)
{
    return getFirstDigit(x) + getSecondDigit(x);
}
