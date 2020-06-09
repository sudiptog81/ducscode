#include <iostream>
#define MAX_SIZE 255

using namespace std;

void swap(int *, int *);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void binarySearch(const int[], int, int);

int main()
{
    int size = 0;
    cout << "Enter array size: ";
    cin >> size;

    int array[MAX_SIZE] = {0};
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
        cin >> array[i];

    mergeSort(array, 0, size - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    int key = 0;
    cout << "Enter number to search: ";
    cin >> key;

    binarySearch(array, size, key);

    return 0;
}

void swap(int *p, int *q)
{
    int temp = *q;
    *q = *p;
    *p = temp;
    return;
}

void mergeSort(int a[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
    return;
}

void merge(int a[], int first, int mid, int last)
{
    int sizeL = mid - first + 1;
    int sizeR = last - mid;

    int leftHalf[MAX_SIZE], rightHalf[MAX_SIZE];
    for (int i = 0; i < sizeL; i++)
        leftHalf[i] = a[first + i];
    for (int i = 0; i < sizeR; i++)
        rightHalf[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = first;

    while (i < sizeL && j < sizeR)
    {
        if (leftHalf[i] < rightHalf[j])
            a[k++] = leftHalf[i++];
        else if (leftHalf[i] > rightHalf[j])
            a[k++] = rightHalf[j++];
        else
        {
            a[k++] = leftHalf[i++];
            j++;
        }
    }

    while (i < sizeL)
        a[k++] = leftHalf[i++];

    while (j < sizeR)
        a[k++] = rightHalf[j++];

    return;
}

void binarySearch(const int a[], int b, int c)
{
    if (b <= 0)
        return;

    int first = 0, last = b, mid = 0;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (c > a[mid])
            first = mid + 1;
        else if (c < a[mid])
            last = mid - 1;
        else
        {
            cout << "Element found at "
                 << "index " << mid << "\n";
            return;
        }
    }

    cout << "Element not found";
    return;
}
