#include <iostream>

using namespace std;

void display(int a, int b = 5);

int main()
{
    display(1);
    display(1, 10);
    return 0;
}

void display(int a, int b)
{
    cout << a << " " << b << endl;
    return;
}