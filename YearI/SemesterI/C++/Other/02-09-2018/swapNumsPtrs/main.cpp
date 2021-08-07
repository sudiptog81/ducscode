#include <iostream>

using namespace std;

void swap(int *, int *);

int main()
{
    int a, b, *pa = &a, *pb = &b;
    cout << "Enter 2 Integers: ";
    cin >> *pa >> *pb;
    swap(pa, pb);
    cout << "After Swapping: ";
    cout << *pa << " " << *pb << endl;
    return 0;
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
    return;
}