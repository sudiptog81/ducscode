/**
 * Write a program to implement Binary Search using recursion.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>

using namespace std;

int binarySearch(int *arr, int el, int first, int last)
{
    if (first <= last)
    {
        int mid = (first + last) / 2;
        if (el == arr[mid])
            return mid;
        else if (el < arr[mid])
            binarySearch(arr, el, first, mid - 1);
        else if (el > arr[mid])
            binarySearch(arr, el, mid + 1, last);
    }
    else
        return -1;
}

int main()
{
    int n;
    cout << "Enter Number of Elements in Array: ";
    cin >> n;
    int arr[n];
    cout << "Enter Elements of Array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int el;
    cout << "Enter Element to Search: ";
    cin >> el;
    cout << "RESULT: ";
    int index = binarySearch(arr, el, 0, n - 1);
    if (index == -1)
        cout << el << " was not found in the Array.";
    else
        cout << el << " found at Index " << index
             << " (Position " << (index + 1)
             << ") in the Arrray.";
    return 0;
}
