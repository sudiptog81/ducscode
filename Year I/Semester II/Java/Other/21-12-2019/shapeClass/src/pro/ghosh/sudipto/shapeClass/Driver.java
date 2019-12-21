package pro.ghosh.sudipto.shapeClass;

public class Driver {
    public static void main(String[] args) {
        Triangle t = new Triangle(1);
        System.out.println(
                "Area of an Equilateral Triangle with side 1 cm is "
                        + t.getArea() + " sq cm."
        );

        Square s = new Square(1);
        System.out.println(
                "Area of a Square with side 1 cm is "
                        + s.getArea() + " sq cm."
        );

    }
}
