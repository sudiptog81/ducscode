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

class B
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
    cout << "Enter values for d, e and f: ";
    cin >> d >> e >> f;
    return;
}

void B::Bprint()
{
    cout << "d: " << d << " e: " << e
         << " f: " << f << endl;
    return;
}

class C : private A, public B
{
private:
    int g;

public:
    int h;
    void Cread();
    void Cprint();
};

void C::Cread()
{
    Aread();
    Bread();
    cout << "Enter values for g and h: ";
    cin >> g >> h;
    return;
}

void C::Cprint()
{
    Aprint();
    Bprint();
    cout << "g: " << g
         << " h: " << h
         << endl;
    return;
}

int main()
{
    C ob;

    ob.Cread();
    ob.Cprint();

    return 0;
}