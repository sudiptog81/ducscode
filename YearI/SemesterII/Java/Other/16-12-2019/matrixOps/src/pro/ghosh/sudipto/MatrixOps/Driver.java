package pro.ghosh.sudipto.MatrixOps;

import java.util.Scanner;

public class Driver {
    static int getChar(Scanner scanner) {
        System.out.print("Continue (Y = 1 | N = 0) ? ");
        return scanner.nextInt();
    }

    static int showMenu(Scanner scanner) {
        System.out.println("= MENU ==================================");
        System.out.println("  (1) M     \t(2) N");
        System.out.println("  (3) M + N \t(4) M - N");
        System.out.println("  (5) M . N \t(6) M'");
        System.out.println("  (7) N'    \t(0) Exit");
        System.out.println();
        System.out.print("Enter Choice: ");
        return scanner.nextInt();
    }

    public static void main(String[] args) {
        int a, b, c;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter dimensions of Matrix M: ");
        a = scanner.nextInt();
        b = scanner.nextInt();

        Matrix m = new Matrix(a, b);
        System.out.println("Enter Data: ");
        m.get(scanner);

        System.out.print("Enter dimensions of Matrix N: ");
        a = scanner.nextInt();
        b = scanner.nextInt();

        Matrix n = new Matrix(a, b);
        System.out.println("Enter Data: ");
        n.get(scanner);

        do {
            c = showMenu(scanner);
            System.out.println();
            switch (c) {
                case 1:
                    System.out.println("MATRIX M");
                    System.out.println("--------");
                    m.put();
                    break;
                case 2:
                    System.out.println("MATRIX N");
                    System.out.println("--------");
                    n.put();
                    break;
                case 3:
                    System.out.println("SUM");
                    System.out.println("---");
                    try {
                        m.add(n).put();
                    } catch (MatrixException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 4:
                    System.out.println("DIFFERENCE");
                    System.out.println("----------");
                    try {
                        m.subtract(n).put();
                    } catch (MatrixException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 5:
                    System.out.println("DOT PRODUCT");
                    System.out.println("-----------");
                    try {
                        m.dot(n).put();
                    } catch (MatrixException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 6:
                    System.out.println("TRANSPOSE OF M");
                    System.out.println("--------------");
                    m.transpose().put();
                    break;
                case 7:
                    System.out.println("TRANSPOSE OF N");
                    System.out.println("--------------");
                    n.transpose().put();
                    break;
                default:
                    break;
            }

            if (c != 0) {
                c = getChar(scanner);
                System.out.println();
            }
        } while (c != 0);

        scanner.close();
    }
}
