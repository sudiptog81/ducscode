#include <iostream>
#define MAX_COLS 100
#define MAX_ROWS 100

using namespace std;

void multiplyMatrices(const int a[][MAX_COLS], int m,
                      const int b[][MAX_COLS], int n,
                      int p);

int main()
{
  int m, p, q, n;

  // getting dimensions of the matrices
  cout << "Enter dimensions of Matrix A: ";
  cin >> m >> p;
  cout << "Enter dimensions of Matrix B: ";
  cin >> q >> n;

  if (p == q)
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

    // calling function to multiply
    // matrix A and B
    multiplyMatrices(matrix1, m, matrix2, n, p);
  }
  else
    cout << "\nMatrices cannot be multiplied!\n";

  return 0;
}

void multiplyMatrices(const int a[][MAX_COLS], int m,
                      const int b[][MAX_COLS], int n,
                      int p)
{
  int c[m][n];

  // initializing all elements of matrix
  // C to 0
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      c[i][j] = 0;

  // calulating dot product of matrices
  // A and B and storing results in C
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < p; k++)
        c[i][j] += a[i][k] * b[k][j];

  // displaying the dot product of the
  // matrices A and B
  cout << "\nMatrix C = A.B\n--------------\n";
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      cout << c[i][j] << " ";
    cout << endl;
  }

  return;
}
