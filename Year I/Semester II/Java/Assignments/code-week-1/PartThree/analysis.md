When the `SubClass` is instantiated, the constructor of its Parent / Super Class is called. In this case, the Super Class is `AbstractClass` which prints the line `"This is constructor of abstract class"` to the console which forms the output of the code in the `AbstractClass` constructor. This also proves that `AbstractClass` is inherited by `SubClass`.

`SubClass` provides a concrete definition of `a_method()` in `AbstractClass`. The definition of `a_method()` causes the program to print `"This is abstract method"`.

Definition of `normal_method()` in the `AbstractClass` prints the line `"This is the normal method of abstract class"`