# Assignment - Week 1

## Examiner
Department of Computer Science, University of Delhi

## Part One
What will be the output of the following programs?

- ```java
    class A
    {
        public A()
        {
            System.out.println("Class A Constructor");
        }
    }

    class B extends A
    {
        public B()
        {
            System.out.println("Class B Constructor");
        }
    }

    class C extends B
    {
        public C()
        {
            System.out.println("Class C Constructor");
        }
    }

    public class MainClass
    {
        public static void main(String[] args)
        {
            C c = new C();
        }
    }
    ```
-   ```java
    class A
    {
        String s = "Class A";
    }

    class B extends A
    {
        String s = "Class B";
        {
            System.out.println(super.s);
        }
    }

    class C extends B
    {
        String s = "Class C";
        {
            System.out.println(super.s);
        }
    }

    public class MainClass
    {
        public static void main(String[] args)
        {
            C c = new C();
            System.out.println(c.s);
        }
    }
    ```
-   ```java
    class CommLine {
        public static void main(String args[]) {
            for(int i = 0; i < args.length; i++)
              System.out.println("args[" + i + "]: " + args[i]);
        }
    }
    ```
    
## Part Two
Can abstract class have constructors in Java?

## Part Three
Create an abstract class `Parent` with a method `message`. It has two subclasses each having a method with the same name `message` that prints `"This is first subclass"` and `"This is second subclass"` respectively. 

Call the methods `message` by creating an object for each subclass.

## Part Four
An abstract class has a construtor which prints `"This is constructor of abstract class"`, an abstract
method named `a_method` and a non-abstract method which prints `"This is a normal method of abstract class"`.

A class `SubClass` inherits the abstract class and has a method named `a_method` which
prints `"This is abstract method"`. Now create an object of `SubClass` and call the abstract method and the
non-abstract method. 

Analyse the result.

---

Updated on March 18, 2020