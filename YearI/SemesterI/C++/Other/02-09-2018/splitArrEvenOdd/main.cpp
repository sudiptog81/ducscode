#include <iostream>
#define MAX_ELEMS 100

using namespace std;

int main()
{
    int n, i, j, k;
    int arr[MAX_ELEMS], even[MAX_ELEMS],
        odd[MAX_ELEMS];
    cout << "Enter size of the array: ";
    cin >> n;

    cout << "Enter elements: ";
    for (i = 0, j = 0; i < n; i++)
        cin >> arr[i];

    for (i = 0, k = 0, j = 0; i < n; i++)
        if (arr[i] % 2)
            odd[k++] = arr[i];
        else
            even[j++] = arr[i];

    cout << "Even elements: ";
    for (i = 0; i < j; i++)
        cout << even[i] << " ";

    cout << endl;

    cout << "Odd elements: ";
    for (i = 0; i < k; i++)
        cout << odd[i] << " ";

    cout << endl;

    return 0;
}