
/**
 *  Create a class Triangle. Include overloaded functions
 *  for calculating area. Overload the assignment and the
 *  equality operator.
 *
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 27 - 09- 2019
 */

#include <iostream>

using namespace std;

class Triangle
{
private:
    int breadth;
    int height;

public:
    Triangle(int, int);

    void calculateArea();
    void calculateArea(float, float);

    void operator=(Triangle &);
    void operator==(Triangle &);
};

Triangle::Triangle(int x = 0, int y = 0)
{
    breadth = x;
    height = y;
}

void Triangle::calculateArea()
{
    cout << "Area of Triangle: "
         << 0.5 * breadth * height
         << endl;

    return;
}

void Triangle::calculateArea(float x, float y)
{
    cout << "Area (Overloaded): "
         << 0.5 * x * y
         << endl;

    return;
}

void Triangle::operator=(Triangle &o)
{
    breadth = o.breadth;
    height = o.height;

    return;
}

void Triangle::operator==(Triangle &o)
{
    if (breadth == o.breadth &&
        height == o.height)
        cout << "Triangles are Equal." << endl;
    else
        cout << "Triangles are Not Equal." << endl;

    return;
}

int main()
{
    int b, h, ch;
    Triangle C;

    cout << "Enter breadth of Triangle 1: ";
    cin >> b;
    cout << "Enter length of Triangle 1: ";
    cin >> h;
    Triangle A(b, h);

    cout << "Enter breadth of Triangle 2: ";
    cin >> b;
    cout << "Enter length of Triangle 2: ";
    cin >> h;
    Triangle B(b, h);

    do
    {
        cout << "\n(1) Calculate Area of Triangle 1"
             << "\n(2) Calculate Area of Triangle 2"
             << "\n(3) Overload Area Calculation"
             << "\n(4) Assign A to C"
             << "\n(5) Check Equality of A and B"
             << "\n(6) Check Equality of A and C"
             << "\n(7) Exit\n"
             << "Enter Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            A.calculateArea();
            break;
        case 2:
            B.calculateArea();
            break;
        case 3:
            cout << "\nEnter breadth (for overload): ";
            cin >> b;
            cout << "Enter height (for overload): ";
            cin >> h;
            A.calculateArea(b, h);
            break;
        case 4:
            C = A;
            break;
        case 5:
            A == B;
            break;
        case 6:
            A == C;
            break;
        case 7:
        default:
            break;
        }
    } while (ch != 7);

    cout << "\nExiting...\n";

    return 0;
}
