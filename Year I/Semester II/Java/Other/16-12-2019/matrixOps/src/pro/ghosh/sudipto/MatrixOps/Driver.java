package pro.ghosh.sudipto.MatrixOps;

import java.util.Scanner;

public class Driver {
    public static void main(String[] args) {
        int a, b;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter dimensions of Matrix M: ");
        a = scanner.nextInt();
        b = scanner.nextInt();

        Matrix m = new Matrix(a, b);
        System.out.println("Enter Data: ");
        m.get();

        System.out.println("MATRIX M");
        System.out.println("--------");
        m.put();

        System.out.print("Enter dimensions of Matrix N: ");
        a = scanner.nextInt();
        b = scanner.nextInt();

        Matrix n = new Matrix(a, b);
        System.out.println("Enter Data: ");
        n.get();

        System.out.println("MATRIX N");
        System.out.println("--------");
        n.put();

        System.out.println("SUM");
        System.out.println("---");
        try {
            m.add(n).put();
        } catch (MatrixException e) {
            e.getMessage();
        }

        System.out.println("DIFFERENCE");
        System.out.println("----------");
        try {
            m.subtract(n).put();
        } catch (MatrixException e) {
            e.getMessage();
        }

        System.out.println("DOT PRODUCT");
        System.out.println("-----------");
        try {
            m.dot(n).put();
        } catch (MatrixException e) {
            e.getMessage();
        }

        System.out.println("TRANSPOSE OF M");
        System.out.println("--------------");
        m.transpose().put();

        System.out.println("TRANSPOSE OF N");
        System.out.println("--------------");
        n.transpose().put();
    }
}
