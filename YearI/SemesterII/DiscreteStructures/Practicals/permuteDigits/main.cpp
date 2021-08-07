/**
 * Write a Program that generates all the permutations of a given set of 
 * digits, with or without repetition.
 *
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
using namespace std;

void printPermutations(int *arr, int i, int r)
{
    if (i == r)
    {
        for (int j = 0; j < r; j++)
            cout << arr[j];
        cout << endl;
    }
    else
    {
        for (int j = i; j < r; j++)
        {
            swap(arr[i], arr[j]);
            printPermutations(arr, i + 1, r);
            swap(arr[j], arr[i]);
        }
    }
}

int main()
{
    int *array, n;

    cout << "Enter Number of Elements: ";
    cin >> n;
    array = new int[n];
    cout << "Enter the Elements of the Set: ";
    for (int i = 0; i < n; i++)
        cin >> array[i];

    cout << "Possible Permutations: \n";
    printPermutations(array, 0, n);

    return 0;
}