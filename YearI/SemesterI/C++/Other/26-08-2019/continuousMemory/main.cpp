#include <iostream>

using namespace std;

int main()
{
    /* if arr[0] is stored at address x, then arr[1] is 
    ** stored at x + sizeof(int), arr[2] is stored at x
    ** + sizeof(int) + sizeof(int) and so on.
    */

    int arr[5], i;

    cout << "Size of integer in this compiler is " << sizeof(int)
         << " bytes" << endl;

    for (i = 0; i < 5; i++)
        cout << "Address arr[" << (unsigned long)i << "] is "
             << &arr[i] << endl;

    return 0;
}