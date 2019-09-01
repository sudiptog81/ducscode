#include <iostream>
#define MAX_COLS 100
#define MAX_ROWS 100

using namespace std;

void addMatrices(const int a[][MAX_COLS], int m,
                 const int b[][MAX_COLS], int n);

int main()
{
  int m, p, q, n;

  // getting dimensions of the matrices
  cout << "Enter dimensions of Matrix A: ";
  cin >> m >> p;
  cout << "Enter dimensions of Matrix B: ";
  cin >> q >> n;

  if (m == q && p == n)
  {
    int matrix1[MAX_ROWS][MAX_COLS];
    int matrix2[MAX_ROWS][MAX_COLS];

    // getting elements of matrix A
    cout << "\nMatrix A\n----------\n";
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < p; j++)
        cin >> matrix1[i][j];
    }

    // getting elements of matrix B
    cout << "\nMatrix B\n----------\n";
    for (int i = 0; i < q; i++)
    {
      for (int j = 0; j < n; j++)
        cin >> matrix2[i][j];
    }

    // calling function to add matrices A and B
    addMatrices(matrix1, m, matrix2, n);
  }
  else
    cout << "\nMatrices cannot be added!\n";

  return 0;
}

void addMatrices(const int a[][MAX_COLS], int m,
                 const int b[][MAX_COLS], int n)
{
  int c[m][n];

  // initializing all elements of matrix
  // C to 0
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      c[i][j] = 0;

  // adding each element of the matrices
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      c[i][j] = a[i][j] + b[i][j];

  // displaying the sum of matrices A and B
  cout << "\nMatrix C = A+B\n--------------\n";
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      cout << c[i][j] << " ";
    cout << endl;
  }

  return;
}
