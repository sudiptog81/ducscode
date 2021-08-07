#include <iostream>

using namespace std;

// Example of a Class
class A
{
private: // Private Access Specifier
    // Data Members

    int a;
    int b;

public: // Public Access Specifier
    // Declarations of Member Functions

    /**
     *  Constructors
     *  ------------
     *  a constructor is a member function
     *  which initializes data members
     */
    A();         // Default
    A(int);      // Parameterized (1)
    A(int, int); // Parameterized (2)
    A(A &);      // Copy Constructor

    /**
     *  Destructors
     *  ------------
     *  a destructor releases the memory
     *  occupied by the objects when they
     *  are not in use
     */
    ~A() {}

    /**
     *  Mutator
     *  ------------
     *  changes the state of an object
     */
    void change(int, int);

    /**
     *  Accessor
     *  ------------
     *  cannot change, but can access the
     *  state of an object
     */
    void print();

    // Non-Member Functions

    /**
     *  Freinds
     *  ------------
     *  non-member funcs with the right to 
     *  access all private and protected 
     *  data members of a class
     */
    friend void add(A &, A &);
};

// Defining Member and Non-Member Functions

A::A()
{
    a = 5;
    b = 7;
}

A::A(int x)
{
    a = x;
    b = 7;
}

A::A(int x, int y)
{
    a = x;
    b = y;
}

A::A(A &obj)
{
    a = obj.a;
    b = obj.b;
}

void A::change(int x, int y)
{
    a = x;
    b = y;

    return;
}

void A::print()
{
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return;
}

void add(A &ob1, A &ob2)
{
    cout << "Sum of a's: " << ob1.a + ob2.a
         << endl;
    cout << "Sum of b's: " << ob1.b + ob2.b
         << endl;

    return;
}

int main()
{
    cout << "Object 1:\n";
    A obj1;
    obj1.print();
    cout << endl;

    cout << "Object 2:\n";
    A obj2(3);
    obj2.print();
    cout << endl;

    cout << "Object 3:\n";
    A obj3(2, 3);
    obj3.print();
    cout << "\nChanging Object 3 ...\n";
    obj3.change(9, 11);
    obj3.print();
    cout << endl;

    cout << "Object 4:\n";
    A obj4(obj2);
    obj4.print();
    cout << endl;

    cout << "Adding Objects 3 and 4 ...\n";
    add(obj3, obj4);
    cout << endl;

    return 0;
}