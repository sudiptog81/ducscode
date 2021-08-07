#include <iostream>
#define MAX_ELEMS 100

using namespace std;

void deleteElement(int[], int, int);

int main()
{
    int n, d, arr[MAX_ELEMS];

    cout << "Enter size of the array: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter index of element to delete: ";
    cin >> d;

    deleteElement(arr, n, d);

    cout << endl;

    return 0;
}

void deleteElement(int a[], int s, int e)
{
    for (int i = 0; i < s; i++)
        if (i == e)
            for (int j = e; j < s; j++)
                a[j] = a[j + 1];
    s--;

    cout << "Compacted array: ";
    for (int i = 0; i < s; i++)
        cout << a[i] << " ";

    return;
}