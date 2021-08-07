#include <iostream>

using namespace std;

class A
{
private:
    int a;

protected:
    int b;

public:
    int c;
    void Aread();
    void Aprint();
};

void A::Aread()
{
    cout << "Enter values for a, b and c: ";
    cin >> a >> b >> c;
    return;
}

void A::Aprint()
{
    cout << "a: " << a << " b: " << b
         << " c: " << c << endl;
    return;
}

class B : private A
{
private:
    int d;

protected:
    int e;

public:
    int f;
    void Bread();
    void Bprint();
};

void B::Bread()
{
    Aread();
    cout << "Enter values for d, e and f: ";
    cin >> d >> e >> f;
    return;
}

void B::Bprint()
{
    Aprint();
    cout << "d: " << d << " e: " << e
         << " f: " << f << endl;
    return;
}

int main()
{
    A ob1;
    B ob2;

    // ob1.a  = 3; error: private data member of class A
    // ob2.a = 5; error: private member not inherited

    ob1.Aread(); // valid
    ob1.Aprint();
    ob2.Bread();
    // ob1.Bread(); parent class doesn't inherit members of derived class
    ob2.Bprint();
    // Bread(); error: cannot call members explicitly
    ob1.c = 15; // valid
    // ob1.b = 12; error: protected members not accessible

    return 0;
}