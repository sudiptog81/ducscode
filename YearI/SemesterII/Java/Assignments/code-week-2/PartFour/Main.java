import java.util.Scanner;

interface shape {
    void area(Scanner sc);
}

class circle implements shape {
    public void area(Scanner sc) {
        System.out.print("Enter Radius of Circle: ");
        double r = sc.nextDouble();
        System.out.println("Area: " + Math.PI * r * r + " sq units");
    }
}

class rectangle implements shape {
    public void area(Scanner sc) {
        System.out.print("Enter Length of Rectangle: ");
        double l = sc.nextDouble();
        System.out.print("Enter Breadth of Rectangle: ");
        double b = sc.nextDouble();
        System.out.println("Area: " + l * b + " sq units");
    }
}

class square implements shape {
    public void area(Scanner sc) {
        System.out.print("Enter Edge Length of Square: ");
        double s = sc.nextDouble();
        System.out.println("Area: " + s * s + " sq units");
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        circle c = new circle();
        c.area(sc);

        rectangle r = new rectangle();
        r.area(sc);

        square s = new square();
        s.area(sc);

        sc.close();
    }
}