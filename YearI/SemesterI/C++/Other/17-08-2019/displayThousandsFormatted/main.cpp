#include <iostream>
#include <iomanip>

using namespace std;

int getHundreds(long);
int getThousands(long);
void displayFormatted(long);

int main()
{
    long num;

    cout << "Enter an integer: ";
    cin >> num;

    displayFormatted(num);

    cout << endl;

    return 0;
}

int getHundreds(long x)
{
    return x % 1000;
}

int getThousands(long x)
{
    return x / 1000;
}

void displayFormatted(long x)
{
    cout << "Formatted: "
         << setw(3) << setfill('0')
         << getThousands(x) << ','
         << setw(3) << setfill('0')
         << getHundreds(x);
}