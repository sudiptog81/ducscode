#include <iostream>

using namespace std;

void search(const int *, int, int);

int main()
{
    int n, size;

    cout << "Enter size of the array: ";
    cin >> size;

    int a[size];

    cout << "Enter values in the array: ";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    cout << "Enter value to be searched: ";
    cin >> n;

    search(a, size, n);

    return 0;
}

void search(const int x[], int size, int el)
{
    int i, flag = 1;

    for (i = 0; i < size; i++)
    {
        if (x[i] == el)
        {
            flag = 0;
            break;
        }
    }

    if (!flag)
        cout << "\nElement is at index " << i << ", position "
             << i + 1 << " :)\n"
             << endl;
    else
        cout << "\nElement not found in the array :(\n"
             << endl;
}
