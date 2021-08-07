/**
 *  WAP that swaps two numbers using pointers
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <iostream>

using namespace std;

void swap(int *, int *);

int main(void)
{
    int x, y;

    // prompt user for input
    cout << "Enter two integers: ";
    cin >> x >> y;

    // display state before function call
    cout << "Before Swapping: \tx: "
         << x << "\ty: " << y << endl;

    // call the swap function and passing
    // the addresses of the integers
    swap(&x, &y);

    // display state after function call
    cout << "After Swapping: \tx: "
         << x << "\ty: " << y << endl;

    return 0;
}

// swaps two integers using pointers
void swap(int *p, int *q)
{
    int temp = *q;
    *q = *p;
    *p = temp;
    return;
}