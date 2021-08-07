#include <iostream>
#define MAX_ROWS 100
#define MAX_COLS 100

using namespace std;

void flatten(const int a[][MAX_COLS], int b, int c, int d[]);

int main()
{
    int m = 0, n = 0;
    int matrix[MAX_ROWS][MAX_COLS] = {0};

    cout << "Enter dimensions of the Multidimensional Array: ";
    cin >> m >> n;

    cout << "\nMultidimensional Array Elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    int array[m * n] = {0};
    flatten(matrix, m, n, array);

    cout << "\nFlattened Array in Row Major Order: ";
    for (int i = 0; i < (m * n); i++)
        cout << array[i] << " ";

    cout << endl;

    return 0;
}

void flatten(const int a[][MAX_COLS], int b, int c, int d[])
{
    for (int i = 0; i < b; i++)
        for (int j = 0; j < c; j++)
            d[c * i + j] = a[i][j];

    return;
}