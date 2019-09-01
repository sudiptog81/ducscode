#include <iostream>
#define MAX_ROWS 100
#define MAX_COLS 100

using namespace std;

void square(int[], int);

int main()
{
    int m, n;

    cout << "Enter dimensions of the matrix: ";
    cin >> m >> n;

    int matrix[m][n];
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    // pass each row to the function
    for (int i = 0; i < m; i++)
        square(matrix[i], n);

    cout << "Matrix with Squared Rows:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/**
 *  Iterates over and squares each element
 *  of the array 
 */
void square(int a[], int b)
{
    for (int i = 0; i < b; i++)
        a[i] = a[i] * a[i];

    return;
}