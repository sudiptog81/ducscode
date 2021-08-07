#include <iostream>
#define MAX_COLS 100
#define MAX_ROWS 100

using namespace std;

void transposeMatrix(const int a[][MAX_COLS], int m, int n);

int main()
{
    int m, n;

    // getting dimensions of the matrices
    cout << "Enter dimensions of Matrix: ";
    cin >> m >> n;

    int matrix[MAX_ROWS][MAX_COLS];

    // getting elements of the matrix
    cout << "\nMatrix\n----------\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    // calling function to transpose
    // the matrix
    transposeMatrix(matrix, m, n);

    return 0;
}

void transposeMatrix(const int a[][MAX_COLS], int m, int n)
{
    int c[n][m];

    // initializing all elements of matrix
    // C to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            c[i][j] = 0;

    // transposing each element of matrix
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            c[j][i] = a[i][j];

    // displaying the transposed matrix
    cout << "\nTranspose of Matrix\n---------------------\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    return;
}
