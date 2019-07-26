#include <iostream>

using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int difference(int a, int b)
{
    return a - b;
}

int product(int a, int b)
{
    return a * b;
}

float quotient(float a, float b)
{
    float q;
    try
    {
        if (b == 0)
        {
            throw 0;
        }
        q = a / b;
    }
    catch (int errCode)
    {
        q = errCode;
    }
    return q;
}

int *getInputs()
{
    static int inputs[2];

    cout << "Enter X: ";
    cin >> inputs[0];
    cout << "Enter Y: ";
    cin >> inputs[1];

    return inputs;
}

int main()
{
    int *inputs = getInputs();
    int x = *(inputs + 0);
    int y = *(inputs + 1);

    for (int z = 0; z < 5; z++)
    {
        switch (z)
        {
        case 1:
            cout << "Sum: " << sum(x, y) << endl;
            break;
        case 2:
            cout << "Difference: " << difference(x, y) << endl;
            break;
        case 3:
            cout << "Product: " << product(x, y) << endl;
            break;
        case 4:
            cout << "Quotient: " << quotient(float(x), float(y)) << endl;
            break;
        default:
            break;
        }
    }

    cout << "Exiting...";

    return 0;
}