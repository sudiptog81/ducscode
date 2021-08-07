/**
 * Create an Exception subclass UnderAge, which prints "Under Age" along with
 * the age value when an object of UnderAge class is printed in the catch
 * statement. Write a class exceptionDemo in which the method test() throws
 * UnderAge exception if the variable age passed to it as argument is less than
 * 18. Write main() method also to show working of the program.
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** UnderAge.java ****/
public class UnderAge extends Exception {
    final private int age;

    public UnderAge(int age) {
        this.age = age;
    }

    @Override
    public String getMessage() {
        return "UnderAge: " + age + " is less than 18";
    }
}