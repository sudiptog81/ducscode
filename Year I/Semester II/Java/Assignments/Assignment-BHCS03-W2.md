# Assignment - Week 2

## Examiner
Department of Computer Science, University of Delhi

## Part One
What will be the output of the following programs?

- ```java
  interface A {
    void myMethod();
  }

  class B {
      public void myMethod() {
          System.out.println("My Method");
      }
  }

  class C extends B implements A {

  }
 
  class MainClass {
      public static void main(String[] args) {
          A a = new C();

          a.myMethod();
      }
  }
  ```
- ```java
  interface P {
      String p = "PPPP";

      String methodP();
  }

  interface Q extends P {
      String q = "QQQQ";

      String methodQ();
  }

  class R implements P, Q {
      public String methodP() {
          return q + p;
      }

      public String methodQ() {
          return p + q;
      }
  }

  public class MainClass { 
      public static void main(String[] args) {
          R r = new R();

          System.out.println(r.methodP());

          System.out.println(r.methodQ());
      }
  }
  ```
    
## Part Two
Create a class `TwoDim` which contains private members as `x` and `y` coordinates in package `P1`. Define the default constructor, a parameterized constructor and override `toString()` method to display the co-ordinates. 

Now reuse this class and in package `P2` create another class `ThreeDim`, adding a new dimension `z` as its private member. Define the constructors for the subclass and override `toString()` method in the subclass also.

Write appropriate methods to show dynamic method dispatch. 

The `main()` function should be in a package `P`.

## Part Three
Define an abstract class `Shape` in package `P1`. Inherit two more classes: `Rectangle` in package `P2` and `Circle` in package `P3`. 

Write a program to ask the user for the type of shape and then using the concept of dynamic method dispatch, display the area of the appropriate subclass. 

Also write appropriate methods to read the data. 

The `main()` function should not be in any package.

## Part Four
Define an interface `shape` which contains a function `area()`. Write the implementation of the interface for circle, rectangle and square. Also write the `main()` to test the interface. Can we declare variable in an Interface?

## Part Five
Can interfaces have constructors?

---

Updated on March 24, 2020