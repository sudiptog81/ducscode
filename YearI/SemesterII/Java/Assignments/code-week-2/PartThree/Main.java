
import java.io.*;

import P1.*;
import P2.*;
import P3.*;

public class Main {
    static int getShapeType() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("==============\n  SHAPE TYPE  \n==============");
        System.out.println(" (1) Rectangle\n (2) Circle");
        System.out.print("Enter Choice: ");
        return Integer.parseInt(br.readLine());
    }

    public static void main(String[] args) throws IOException {
        Shape ref;
        boolean flag = false;

        while (!flag) {
            switch (getShapeType()) {
                case 1:
                    flag = true;
                    ref = new Rectangle();
                    System.out.println("Area: " + ref.area() + " sq units");
                    break;
                case 2:
                    flag = true;
                    ref = new Circle();
                    System.out.println("Area: " + ref.area() + " sq units");
                    break;
                default:
                    System.err.println("Invalid Option");
                    break;
            }
        }
    }
}