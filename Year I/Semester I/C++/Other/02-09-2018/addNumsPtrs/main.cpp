#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int *pa = &a;     // points to a
    int *pb = &b;     // points to b
    int *pc = &c;     // points to c
    int **psum = &pc; // points to pc

    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;

    *pc = (*pa) + (*pb); // changing value of c

    /**
     * accessing value of c by deferencing twice
     * as psum->pc->c 
     */
    cout << "Sum of A and B: " << (**psum);
    return 0;
}