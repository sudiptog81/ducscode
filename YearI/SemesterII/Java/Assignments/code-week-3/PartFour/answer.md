# Can we write only `try` block without `catch` and `finally` blocks?

No, it shall result in a compilation error `error: 'try' without 'catch', 'finally' or resource declarations`. 

The `try` block must be followed by either a `catch` or `finally` block. We can remove either `catch` block or `finally` block but not both of them. An exception can be made in the case of `try-with-resources` blocks which does not necessarily need to be followed by `catch` or `finally` blocks.

## Valid Snippets

-  ```java
    try {
        // ...
    } catch(Exception e) {
        // ...
    }
    ```

-  ```java
    try {
        // ...
    } finally {
        // ...
    }
    ```

-   ```java
    try {
        // ...
    } catch(Exception e) {
        // ...
    } finally {
        // ...
    }
    ```

-   ```java
    try (Scanner sc = new Scanner(System.in)) {
        // ...
    }
    ```