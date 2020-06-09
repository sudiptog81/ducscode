# Assignment - Week 3

## Examiner
Department of Computer Science, University of Delhi

## Part One
What will be the output (along with explanation) of the following programs?

-   ```java
    public class JavaHungry {
        public static void main(String args[]) {
            try {
                System.out.print("A");
                int num = 99 / 0;
                System.out.print("B");
            } catch (ArithmeticException ex) {
                System.out.print("C");
            } catch (Exception ex) {
                System.out.print("D");
            }
            System.out.print("E");
        }
    }
    ```
-   ```java
    public class JavaHungry {
        public static void main(String args[]) {
            try {
                System.out.print("A");
                int num = 99 / 0;
                System.out.print("B");
            } catch (ArithmeticException ex) {
                System.out.print("C");
            } catch (Exception ex) {
                System.out.print("D");
            } finally {
                System.out.print("E");
            }
            System.out.print("F");
        }
    }
    ```

## Part Two
Create an `Exception` subclass `UnderAge`, which prints "Under Age" along with the `age` value when an object of `UnderAge` class is printed in the catch statement. Write a class `exceptionDemo` in which the method `test()` throws `UnderAgeException` if the variable `age` passed to it as argument is less than `18`. Write `main()` method also to show working of the program.

## Part Three
Write a program to implement stack. Use exception handling to manage underflow and overflow conditions.

## Part Four
Can we write only `try` block without `catch` and `finally` blocks?

## Part Five
There are three statements in a `try` block – `statement1`, `statement2` and `statement3`. After that there is a `catch` block to catch the exceptions occurred in the `try` block. Assume that exception has occurred in `statement2`. Does `statement3` get executed or not?

---

Updated on April 02, 2020