
/**
 *  Create Matrix class. Write a menu-driven program 
 *  to perform the following Matrix operations:
 *      (a) Sum     (b) Difference
 *      (c) Product (d) Transpose
 *
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 27 - 09- 2019
 */

#include <iostream>
#define MAX_DIM 100

using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int matrix[MAX_DIM][MAX_DIM];

public:
    Matrix(int, int);

    void get();
    void put();

    void sum(Matrix &);
    void difference(Matrix &);
    void product(Matrix &);
    void transpose();
};

Matrix::Matrix(int r = 3, int c = 3)
{
    rows = r;
    cols = c;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0;
}

void Matrix::get()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element (" << i << "," << j << "): ";
            cin >> matrix[i][j];
        }

    return;
}

void Matrix::put()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void Matrix::sum(Matrix &o)
{
    if (rows != o.rows || cols != o.cols)
    {
        cout << "Matrices cannot be added." << endl;
        return;
    }

    Matrix temp(rows, cols);

    cout << "SUM:\n\n";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp.matrix[i][j] = matrix[i][j] + o.matrix[i][j];

    temp.put();

    return;
}

void Matrix::difference(Matrix &o)
{
    if (rows != o.rows || cols != o.cols)
    {
        cout << "Matrices cannot be subtracted." << endl;
        return;
    }

    Matrix temp(rows, cols);

    cout << "DIFFERENCE:\n\n";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp.matrix[i][j] = matrix[i][j] - o.matrix[i][j];

    temp.put();

    return;
}

void Matrix::product(Matrix &o)
{
    if (cols != o.rows)
    {
        cout << "Matrices cannot be multiplied." << endl;
        return;
    }

    Matrix temp(rows, o.cols);

    cout << "PRODUCT:\n\n";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            for (int k = 0; k < o.rows; k++)
                temp.matrix[i][j] += matrix[i][k] * o.matrix[k][j];

    temp.put();

    return;
}

void Matrix::transpose()
{
    Matrix temp(cols, rows);

    cout << "TRANSPOSE:\n\n";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp.matrix[j][i] = matrix[i][j];

    temp.put();

    return;
}

void getInputs(Matrix &, Matrix &);
void handleMenu(Matrix &, Matrix &);

int main()
{
    int r1, c1, r2, c2;

    cout << "Enter dimensions of Matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter dimensions of Matrix B: ";
    cin >> r2 >> c2;

    Matrix A(r1, c1), B(r2, c2);

    getInputs(A, B);
    handleMenu(A, B);

    cout << "Exiting...\n";

    return 0;
}

void getInputs(Matrix &A, Matrix &B)
{
    cout << "\nMatrix A\n---------\n";
    A.get();
    cout << endl;
    cout << "\nMatrix B\n---------\n";
    B.get();
    cout << endl;

    return;
}

void handleMenu(Matrix &A, Matrix &B)
{
    int ch = 0;

    do
    {
        cout << "\nMenu\n-------\n(1) Add\n(2) Subtract";
        cout << "\n(3) Multiply\n(4) Transpose A\n(5) Transpose B";
        cout << "\n(6) View Matrices\n(7) Exit\n\nEnter Choice: ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            A.sum(B);
            break;
        case 2:
            A.difference(B);
            break;
        case 3:
            A.product(B);
            break;
        case 4:
            A.transpose();
            break;
        case 5:
            B.transpose();
            break;
        case 6:
            cout << "Matrix A\n---------\n";
            A.put();
            cout << endl;
            cout << "Matrix B\n---------\n";
            B.put();
            break;
        case 7:
        default:
            break;
        }
    } while (ch != 7);

    return;
}