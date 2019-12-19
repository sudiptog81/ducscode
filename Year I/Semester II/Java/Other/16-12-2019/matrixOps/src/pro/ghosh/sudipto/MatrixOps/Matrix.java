package pro.ghosh.sudipto.MatrixOps;

import java.util.Scanner;

public class Matrix {
    final int row;
    final int col;
    final int[][] matrix;

    /**
     * Constructor for Matrix Class
     *
     * @param m rows
     * @param n columns
     */
    public Matrix(int m, int n) {
        row = m;
        col = n;
        matrix = new int[m][n];
    }

    /**
     * Getter for Matrix Class
     */
    public void get() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        System.out.println();
    }

    /**
     * Setter for Matrix Class
     */
    public void put() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * Add Matrices together
     *
     * @param b Matrix
     * @return Matrix
     * @throws MatrixException Dimension Mismatch
     */
    public Matrix add(Matrix b) throws MatrixException {
        if (row == b.row && col == b.col) {
            Matrix t = new Matrix(row, b.col);
            for (int i = 0; i < t.row; i++) {
                for (int j = 0; j < t.col; j++) {
                    t.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
                }
            }
            return t;
        } else {
            throw new MatrixException();
        }
    }

    /**
     * Subtract Matrices from one another
     *
     * @param b Matrix
     * @return Matrix
     * @throws MatrixException Dimension Mismatch
     */
    public Matrix subtract(Matrix b) throws MatrixException {
        if (row == b.row && col == b.col) {
            Matrix t = new Matrix(row, b.col);
            for (int i = 0; i < t.row; i++) {
                for (int j = 0; j < t.col; j++) {
                    t.matrix[i][j] = matrix[i][j] - b.matrix[i][j];
                }
            }
            return t;
        } else {
            throw new MatrixException();
        }
    }

    /**
     * Multiply Matrices together
     *
     * @param b Matrix
     * @return Matrix
     * @throws MatrixException Dimension Mismatch
     */
    public Matrix dot(Matrix b) throws MatrixException {
        if (col == b.row) {
            Matrix t = new Matrix(row, b.col);
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    for (int k = 0; k < col; k++) {
                        t.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
                    }
                }
            }
            return t;
        } else {
            throw new MatrixException();
        }
    }

    /**
     * Transpose a Matrix
     *
     * @return Matrix
     */
    public Matrix transpose() {
        Matrix t = new Matrix(col, row);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                t.matrix[j][i] = matrix[i][j];
            }
        }
        return t;
    }

}
