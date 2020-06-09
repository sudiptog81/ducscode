#include <iostream>

using namespace std;

int merge(const int[], int, const int[],
          int, int[]);

int main()
{
    int m, n;

    cout << "Enter size of Array A: ";
    cin >> m;

    int array1[m];
    cout << "Enter elements of sorted Array A: ";
    for (int i = 0; i < m; i++)
        cin >> array1[i];

    cout << "Enter size of Array B: ";
    cin >> n;

    int array2[n];
    cout << "Enter elements of sorted Array B: ";
    for (int i = 0; i < n; i++)
        cin >> array2[i];

    int array3[m + n];
    int k = merge(array1, m, array2, n, array3);

    cout << "Merged Array: ";
    for (int i = 0; i < k; i++)
        cout << array3[i] << " ";

    cout << endl;

    return 0;
}

/**
 *  Merges two sorted 1-D arrays and
 *  returns the length of the merged
 *  array
 */
int merge(const int a[], int m, const int b[],
          int n, int c[])
{
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        // if element in first array is
        // lesser than the element in the
        // second array, increment counter
        // of the first array
        if (a[i] < b[j])
        {

            c[k] = a[i];
            i++;
            k++;
        }
        // if element in second array is
        // lesser than the element in the
        // first array, increment counter
        // of the second array
        else if (a[i] > b[j])
        {

            c[k] = b[j];
            j++;
            k++;
        }
        // if elements in both arrays are
        // equal, add a single element and
        // increment both counters
        else
        {

            c[k] = a[i];
            i++;
            j++;
            k++;
        }
    }

    // if the first array is not finished
    if (i != m)
    {
        // add remaining elements of the
        // first array
        while (i < m)
        {
            c[k] = a[i];
            k++;
            i++;
        }
    }

    // if the second array is not finished
    if (j != n)
    {
        // add remaining elements of the
        // second array
        while (j < n)
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }

    // return the actual length of
    // the merged array
    return k;
}