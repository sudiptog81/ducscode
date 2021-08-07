The statements preceding the one which throws the exception shall be executed in their original order i.e. `statement1` shall be executed as-is.

In case that `statement2` throws an exception in the `try` block, the execution skips to the code in the `catch` block.

Hence, `statement3` will not be executed.

Example:
```java
public class Main {
    public static void main(String[] args) {
        try {
            System.out.println(1);
            System.out.println(2/0);
            System.out.println(3);
        } catch (Exception e) {
            System.out.println("Caught");
        }
    }
}

/**
 * OUTPUT:
 * 1
 * Caught
 */
```