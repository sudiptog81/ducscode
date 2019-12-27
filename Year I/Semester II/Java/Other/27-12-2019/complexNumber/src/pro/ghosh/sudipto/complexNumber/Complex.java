package pro.ghosh.sudipto.complexNumber;

/**
 * Design a class Complex having a real part (x) and an imaginary part (y). Provide methods
 * to perform the following on complex numbers:
 * -   Add two complex numbers
 * -   Multiply two complex numbers
 * -   toString() method to display complex numbers in the form: x + i y
 *
 * @author sudipto@ghosh.pro University of Delhu
 */
public class Complex {
    private int x;
    private int y;

    /**
     * Parameterized Constructor of Complex class
     *
     * @param real      Real Part
     * @param imaginary Imaginary Part
     */
    public Complex(int real, int imaginary) {
        this.x = real;
        this.y = imaginary;
    }

    /**
     * Add two Complex Objects
     *
     * @param o Complex Object
     * @return Complex Object
     */
    public Complex add(Complex o) {
        return new Complex(
                this.x + o.x,
                this.y + o.y
        );
    }

    /**
     * Multiply two Complex Objects
     *
     * @param o Complex Object
     * @return Complex Object
     */
    public Complex multiply(Complex o) {
        return new Complex(
                this.x * o.x - this.y * o.y,
                this.x * o.y + o.x * this.y
        );
    }

    /**
     * Type Conversion to String
     *
     * @return String Representation
     */
    @Override
    public String toString() {
        return x + " + i " + y;
    }
}
