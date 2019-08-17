#include <iostream>
#include <iomanip>

using namespace std;

int getHundreds(int);
int getThousands(int);
void displayFormatted(int);

int main()
{
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    displayFormatted(num);

    cout << endl;

    return 0;
}

int getHundreds(int x)
{
    return x % 1000;
}

int getThousands(int x)
{
    return x / 1000;
}

void displayFormatted(int x)
{
    cout << "Formatted: "
         << getThousands(x) << ','
         << setw(3) << setfill('0')
         << getHundreds(x);
}