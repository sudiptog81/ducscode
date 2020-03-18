import java.util.Scanner;

class Main {
    private static Scanner sc;
    private static int[][] matrixA;
    private static int[][] matrixB;
    private static int[][] sum;
    private static int[][] difference;
    private static int[][] product;
    private static int[][] transpose;

    static int[][] getMatrix() throws Exception {
        System.out.print("Enter the dimensions of the matrix: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] matrix = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("Enter element [" + i + "][" + j + "]: ");
                matrix[i][j] = sc.nextInt();
            }
        }

        return matrix;
    }

    static int[][] addMatrices(int[][] a, int[][] b) throws Exception {
        if (a.length != b.length || a[0].length != b[0].length)
            throw new Exception("Dimension Mismatch");

        int[][] sum = new int[a.length][a[0].length];

        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                sum[i][j] = a[i][j] + b[i][j];

        return sum;
    }

    static int[][] subtractMatrices(int[][] a, int[][] b) throws Exception {
        if (a.length != b.length || a[0].length != b[0].length)
            throw new Exception("Dimension Mismatch");

        int[][] diff = new int[a.length][a[0].length];

        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                diff[i][j] = a[i][j] - b[i][j];

        return diff;
    }

    static int[][] multiplyMatrices(int[][] a, int[][] b) throws Exception {
        if (a.length != b[0].length)
            throw new Exception("Dimension Mismatch");

        int[][] prod = new int[a.length][b[0].length];

        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < b[0].length; j++)
                for (int k = 0; k < a[0].length; k++)
                    prod[i][j] += a[i][k] * b[k][j];

        return prod;
    }

    static int[][] transposeMatrix(int[][] a) throws Exception {
        int[][] trans = new int[a.length][a[0].length];

        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                trans[i][j] = a[j][i];

        return trans;
    }

    static void displayMatrix(int[][] matrix) {
        for (int[] i : matrix) {
            for (int j : i)
                System.out.print(j + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) throws Exception {
        sc = new Scanner(System.in);

        // Get Matrices
        System.out.println("\nEnter Matrix A:");
        matrixA = getMatrix();
        System.out.println("\nEnter Matrix B:");
        matrixB = getMatrix();

        // Display Matrices
        System.out.println("\nMatrix A:");
        displayMatrix(matrixA);
        System.out.println("\nMatrix B:");
        displayMatrix(matrixB);

        // Add Matrices
        try {
            System.out.println("\nSum: ");
            sum = addMatrices(matrixA, matrixB);
            displayMatrix(sum);
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }

        // Subtract Matrices
        try {
            System.out.println("\nDifference: ");
            difference = subtractMatrices(matrixA, matrixB);
            displayMatrix(difference);
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }

        // Multiply Matrices
        try {
            System.out.println("\nProduct: ");
            product = multiplyMatrices(matrixA, matrixB);
            displayMatrix(product);
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }

        // Transpose Matrices
        try {
            System.out.println("\nTranspose A: ");
            transpose = transposeMatrix(matrixA);
            displayMatrix(transpose);

            System.out.println("\nTranspose B: ");
            transpose = transposeMatrix(matrixB);
            displayMatrix(transpose);
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }

        sc.close();
    }
}