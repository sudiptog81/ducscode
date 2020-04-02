
/**
 * Create an Exception subclass UnderAge, which prints "Under Age" along with
 * the age value when an object of UnderAge class is printed in the catch
 * statement. Write a class exceptionDemo in which the method test() throws
 * UnderAge exception if the age passed to it as argument is less than 18.
 * Write main() method also to show working of the program.
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** exceptionDemo.java ****/
import java.util.Scanner;

class exceptionDemo {
    static void test(int age) throws UnderAge {
        if (age < 18)
            throw new UnderAge(age);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Age: ");
        int age = sc.nextInt();
        try {
            test(age);
            System.out.println("Test Successful");
        } catch (UnderAge e) {
            System.err.println(e.getMessage());
            System.out.println("Test Unsuccessful");
        } finally {
            sc.close();
        }
    }
}
