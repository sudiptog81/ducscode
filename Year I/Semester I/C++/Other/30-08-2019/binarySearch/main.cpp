#include <iostream>

using namespace std;

void binarySearch(const int[], int, int);

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int s;
    cout << "Enter element to be searched: ";
    cin >> s;

    binarySearch(arr, n, s);

    return 0;
}

void binarySearch(const int a[], int n, int el)
{
    int first = 0, last = n, mid = 0;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (el > a[mid])
            first = mid + 1; // look in the second half
        else if (el < a[mid])
            last = mid - 1; // look in the first half
        else
            first = last + 1; // force exit
    }

    if (el == a[mid])
        cout << "Element found at index " << mid
             << ", position " << mid + 1 << "!" << endl;
    else
        cout << "Element not found!" << endl;

    return;
}
