#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int);
    Fraction(int, int);
    Fraction(Fraction &);

    ~Fraction() {}

    void display();

    friend Fraction add(Fraction &, Fraction &);
    friend Fraction subtract(Fraction &, Fraction &);
    friend Fraction multiply(Fraction &, Fraction &);
    friend Fraction divide(Fraction &, Fraction &);
};

Fraction::Fraction()
{
    numerator = 1;
    denominator = 1;
}

Fraction::Fraction(int x)
{
    numerator = x;
    denominator = 1;
}

Fraction::Fraction(int x, int y)
{
    if (y == 0)
    {
        cerr << "\nDivision by Zero Not Possible!\n";
        exit(0);
    }

    numerator = x;
    denominator = y;
}

Fraction::Fraction(Fraction &ob)
{
    numerator = ob.numerator;
    denominator = ob.denominator;
}

int gcd(int numerator, int denominator)
{
    int remainder;

    while (denominator != 0)
    {
        remainder = numerator % denominator;
        numerator = denominator;
        denominator = remainder;
    }

    return numerator;
}

void Fraction::display()
{
    int g = gcd(numerator, denominator);

    numerator /= g;
    denominator /= g;

    if (denominator == 1)
        cout << numerator;
    else if (denominator == 0)
        cout << "Division by Zero!";
    else if (numerator < 0 || denominator < 0)
        cout << "-" << abs(numerator)
             << "/" << abs(denominator);
    else
        cout << numerator << "/" << denominator;
}

Fraction add(Fraction &ob1, Fraction &ob2)
{
    Fraction sum;

    sum.numerator = ob1.numerator * ob2.denominator +
                    ob2.numerator * ob1.denominator;
    sum.denominator = ob1.denominator * ob2.denominator;

    return sum;
}

Fraction subtract(Fraction &ob1, Fraction &ob2)
{
    Fraction diff;

    diff.numerator = ob1.numerator * ob2.denominator -
                     ob2.numerator * ob1.denominator;
    diff.denominator = ob1.denominator * ob2.denominator;

    return diff;
}

Fraction multiply(Fraction &ob1, Fraction &ob2)
{
    Fraction product;

    product.numerator = ob1.numerator * ob2.numerator;
    product.denominator = ob1.denominator * ob2.denominator;

    return product;
}

Fraction divide(Fraction &ob1, Fraction &ob2)
{
    Fraction quotient;

    quotient.numerator = ob1.numerator * ob2.denominator;
    quotient.denominator = ob1.denominator * ob2.numerator;

    return quotient;
}

int main()
{
    int a, b;
    Fraction sum, difference, product, quotient;

    cout << "Enter numerator of first fraction: ";
    cin >> a;
    cout << "Enter denominator of first fraction: ";
    cin >> b;
    Fraction frac1(a, b);

    cout << endl;

    cout << "Enter numerator of second fraction: ";
    cin >> a;
    cout << "Enter denominator of second fraction: ";
    cin >> b;
    Fraction frac2(a, b);

    cout << endl;

    cout << "Fraction A: ";
    frac1.display();
    cout << endl;

    cout << "Fraction B: ";
    frac2.display();
    cout << endl;

    cout << endl;

    sum = add(frac1, frac2);
    cout << "Sum: ";
    sum.display();
    cout << endl;

    difference = subtract(frac1, frac2);
    cout << "Difference: ";
    difference.display();
    cout << endl;

    product = multiply(frac1, frac2);
    cout << "Product: ";
    product.display();
    cout << endl;

    quotient = divide(frac1, frac2);
    cout << "Quotient: ";
    quotient.display();
    cout << endl;

    return 0;
}