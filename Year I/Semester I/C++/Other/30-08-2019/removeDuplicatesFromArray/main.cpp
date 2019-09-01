#include <iostream>

using namespace std;

void removeDuplicates(int[], int &);

int main()
{
    int m;
    cout << "Enter size of the array: ";
    cin >> m;

    int array[m] = {0};
    cout << "Array Elements: ";
    for (int i = 0; i < m; i++)
        cin >> array[i];

    removeDuplicates(array, m);

    cout << "Array Elements after removing duplicates: ";
    for (int i = 0; i < m; i++)
        cout << array[i] << " ";

    cout << endl;

    return 0;
}

void removeDuplicates(int a[], int &b)
{
    for (int i = 0; i < b; i++)
        if (a[i] == a[i + 1])
        {
            for (int k = i + 1; k < b; k++)
                a[k] = a[k + 1];
            b--;
        }

    return;
}