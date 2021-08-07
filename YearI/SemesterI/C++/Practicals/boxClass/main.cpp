/**
 *  Create a class Box containing length, breadth and 
 *  height. Include the following methods in it:
 *    (a) Calculate Surface Area
 *    (b) Calculate Volume
 *    (c) Overload + operator (to add two boxes 
 *        length, breadth and height)
 *    (d) Overload operator = = (to check equality of 
 *        two boxes), as a friend function
 *    (e) Overload Assignment operator
 *    (f) Check if its a cube or cuboid
 * 
 *  WAP which takes input from user for length, breadth
 *  and height to test the above class.
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 28 - 09 - 2019
 */

#include <iostream>

using namespace std;

class Box
{
private:
    float length;
    float breadth;
    float height;

public:
    Box();
    Box(Box &);
    Box(float, float, float);
    ~Box() {}

    void show();
    void isCube();
    float calculateVolume();
    float calculateSurfaceArea();

    Box operator+(Box &);
    Box operator=(Box &);
    friend void operator==(Box &, Box &);
};

Box::Box()
{
    length = breadth = height = 0;
}

Box::Box(Box &o)
{
    length = o.length;
    breadth = o.breadth;
    height = o.height;
}

Box::Box(float a, float b, float c)
{
    length = a;
    breadth = b;
    height = c;
}

void Box::show()
{
    cout << "Length: " << length << " units\n";
    cout << "Breadth: " << breadth << " units\n";
    cout << "Height: " << height << " units\n";
    return;
}

void Box::isCube()
{
    if (length == breadth &&
        breadth == height &&
        height == length)
        cout << "Box is a Cube";
    else
        cout << "Box is a Cuboid";
    cout << endl;
    return;
}

float Box::calculateVolume()
{
    return length * breadth * height;
}

float Box::calculateSurfaceArea()
{
    return 2 * (length * breadth +
                breadth * height +
                height * length);
}

Box Box::operator+(Box &o)
{
    Box temp(*this);
    temp.length += o.length;
    temp.breadth += o.breadth;
    temp.height += o.height;
    return temp;
}

Box Box::operator=(Box &o)
{
    length = o.length;
    breadth = o.breadth;
    height = o.height;
    return *this;
}

void operator==(Box &a, Box &o)
{
    if (a.length == o.length &&
        a.breadth == o.breadth &&
        a.height == o.height)
        cout << "Boxes are Equal";
    else
        cout << "Boxes are Not Equal";
    cout << endl;
    return;
}

int main()
{
    Box C;
    int l, b, h;

    cout << "Enter dimensions of Box 1: ";
    cin >> l >> b >> h;
    Box A(l, b, h);

    cout << "Enter dimensions of Box 2: ";
    cin >> l >> b >> h;
    Box B(l, b, h);

    cout << endl;

    cout << "Box 1\n";
    cout << "-----\n";
    A.show();
    cout << endl;
    cout << "Box 2\n";
    cout << "-----\n";
    B.show();

    cout << endl;

    cout << "Surface Area\n";
    cout << "------------\n";
    cout << "Box 1: " << A.calculateSurfaceArea()
         << " square units" << endl;
    cout << "Box 2: " << B.calculateSurfaceArea()
         << " square units" << endl;

    cout << endl;

    cout << "Volume\n";
    cout << "------\n";
    cout << "Box 1: " << A.calculateVolume()
         << " cubic units" << endl;
    cout << "Box 2: " << B.calculateVolume()
         << " cubic units" << endl;

    cout << endl;

    cout << "Sum of Box 1 and Box 2\n";
    cout << "----------------------\n";
    (A + B).show();

    cout << endl;

    cout << "Assigning Box 1 to Box 3...\n\n";
    C = A;

    cout << "Equality of Box 1 and Box 2\n";
    cout << "---------------------------\n";
    A == B;

    cout << endl;

    cout << "Equality of Box 1 and Box 3:\n";
    cout << "---------------------------\n";
    A == C;

    cout << endl;

    return 0;
}