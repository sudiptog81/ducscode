#include <string>
#include <cstdlib>
#include <iostream>

#include "error.hpp"

using namespace std;

void othersChild();
void othersParent();
void othersGrandParent();
void math(int, int, char);

int main()
{
    char o;
    int a, b;

    try
    {
        cin >> a >> o >> b;
        math(a, b, o);
        cout << "Throw (1) int (2) float (3) char: ";
        othersGrandParent();
    }
    catch (Error &e)
    {
        cerr << e.print();
    }

    return 0;
}

void othersChild()
{
    try
    {
        int temp;
        cin >> temp;
        switch (temp)
        {
        case 1:
            throw 1;
            break;
        case 2:
            throw 1.0f;
            break;
        case 3:
            throw '1';
            break;
        default:
            throw;
            break;
        }
    }
    catch (int &e)
    {
        cerr << "Exception: Integer " << e << " returned.\n";
    }
    catch (...)
    {
        throw;
    }

    return;
}

void othersParent()
{
    try
    {
        othersChild();
    }
    catch (float &e)
    {
        cerr << "Exception: Float " << e << " returned.\n";
    }
    catch (...)
    {
        throw;
    }

    return;
}

void othersGrandParent()
{
    try
    {
        othersParent();
    }
    catch (...)
    {
        cerr << except();
    }

    return;
}

void math(int a, int b, char o)
{
    switch (o)
    {
    case '+':
        printf("Sum: %d + %d = %d\n", a, b, a + b);
        break;
    case '-':
        printf("Difference: |%d - %d| = %d\n", a, b, abs(a - b));
        break;
    case '*':
        printf("Product: %d * %d = %d\n", a, b, a * b);
        break;
    case '/':
        if (b == 0)
            throw DivByZero();
        else if (b < 0)
            throw DivByNeg();
        else
            printf("Quotient: %d / %d = %.2f\n", a, b,
                   static_cast<float>(a) / static_cast<float>(b));
        break;
    default:
        throw BadOperator();
        break;
    }

    return;
}