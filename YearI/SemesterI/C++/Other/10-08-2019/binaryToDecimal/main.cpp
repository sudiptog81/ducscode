#include <iostream>
#include <iomanip>

using namespace std;

int lsbit(long binary);
bool isValid(long binary);
long bin2dec(long binary);
long powerTwo(int exponent);

int main()
{
    bool validFlag;
    long binary, decimal;

    do
    {
        cout << "Enter a valid binary number: ";
        cin >> binary;
        validFlag = isValid(binary);
        if (!validFlag)
            cout << "Not a valid binary!\n\n";
    } while (!validFlag);

    decimal = bin2dec(binary);

    cout << left;
    cout << endl;
    cout << setw(15) << "Binary: " << binary << endl;
    cout << setw(15) << "Decimal: " << decimal << endl;
    cout << endl;

    return 0;
}

// return the rightmost bit
int lsbit(long binary)
{
    return (binary % 10);
}

// check if user input is valid binary
bool isValid(long binary)
{
    while (binary != 0)
    {
        if (!(binary % 10 == 0 || binary % 10 == 1))
            return false;
        binary /= 10;
    }
    return true;
}

// convert binary to decimal
long bin2dec(long binary)
{
    long decimal = 0;
    for (int i = 0; binary != 0; binary /= 10, i++)
    {
        decimal += lsbit(binary) * powerTwo(i);
    }
    return decimal;
}

// return 2 raised to an exponent
long powerTwo(int exponent)
{
    long res = 1;
    for (int i = 1; i <= exponent; i++)
        res *= 2;
    return res;
}
