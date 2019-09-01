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
    int i, j, k;
    for (i = 0; i < b; i++)
        for (j = i + 1; j < b; j++)
            // check for duplicates
            if (a[i] == a[j])
            {
                // delete the duplicate element
                for (k = j; k < b; k++)
                    a[k] = a[k + 1];

                // decrement size after removing duplicate
                b--;

                // do not increment j if shifting occurs
                j--;
            }

    return;
}