#include <iostream>

using namespace std;

void sumAverage(const int *, int);

int main()
{
    int n, size;

    cout << "Enter size of the array: ";
    cin >> size;

    int a[size];

    cout << "Enter values in the array: ";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    sumAverage(a, size);

    return 0;
}

void sumAverage(const int x[], int size)
{
    int sum = 0;
    float average = 0.0f;

    for (int i = 0; i < size; i++)
        sum += x[i];

    average = (float)sum / (float)size;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return;
}
