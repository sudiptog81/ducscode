# Can we declare variable in an Interface?

Yes, variables can very well be declared inside of interface declarations. ALl variables declared inside interfaces are implicitly `public`, `static` and `final`. It means that variables must be initialized in the interface declaration itself. These variables essentially behave as `public` constants.

Example:
```java
interface Test {
    int num = 1;
    void func();
}
```