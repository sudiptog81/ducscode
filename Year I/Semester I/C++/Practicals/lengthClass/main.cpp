/**
 *  Create a class Length containing feet and inch. 
 *  Include the following functions:
 *      (a) Input Length object
 *      (b) Overload + operator
 *      (c) Overload - operator
 *      (d) Display Length object
 *  
 *  WAP which takes input from user for feet and inch 
 *  to test the above class.
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 28 - 09 - 2019
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class Length
{
private:
    int feet;
    int inch;

public:
    Length();
    Length(Length &);
    ~Length() {}

    void input();
    void display();

    Length operator+(Length &);
    Length operator-(Length &);
};

Length::Length()
{
    feet = inch = 0;
}

Length::Length(Length &o)
{
    feet = o.feet;
    inch = o.inch;
}

void Length::input()
{
    cout << "Enter feet: ";
    cin >> feet;
    cout << "Enter inch: ";
    cin >> inch;
    if (inch >= 12)
        while (inch >= 12)
        {
            inch -= 12;
            feet++;
        }
    return;
}

void Length::display()
{
    cout << "Length: ";
    cout << feet << "\' ";
    cout << inch << "\"\n";
    return;
}

Length Length::operator+(Length &o)
{
    Length temp(*this);
    temp.feet += o.feet;
    temp.inch += o.inch;
    if (temp.inch >= 12)
        while (temp.inch >= 12)
        {
            temp.inch -= 12;
            temp.feet++;
        }
    return temp;
}

Length Length::operator-(Length &o)
{
    Length temp(*this);
    temp.feet -= o.feet;
    temp.inch -= o.inch;
    if (temp.inch >= 12)
        while (temp.inch >= 12)
        {
            temp.inch -= 12;
            temp.feet++;
        }
    temp.feet = abs(temp.feet);
    temp.inch = abs(temp.inch);
    return temp;
}

int main()
{
    Length A, B, sum, diff;

    cout << "Length 1\n";
    cout << "--------\n";
    A.input();
    A.display();
    cout << endl;

    cout << "Length 2\n";
    cout << "--------\n";
    B.input();
    B.display();
    cout << endl;

    cout << "Sum\n";
    cout << "---\n";
    sum = A + B;
    sum.display();
    cout << endl;

    cout << "Difference\n";
    cout << "----------\n";
    diff = A - B;
    diff.display();
    cout << endl;

    return 0;
}
