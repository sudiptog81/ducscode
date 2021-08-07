# Can abstract class have constructors in Java?

Yes, an abstract class can have constructors in Java. We can explicitly provide a constructor to abstract class. Otherwise, the compiler will append a default constructor accepting no arguments to the abstract class. This is true for all classes and it also applies to an abstract class. 

Abstract classes by definition, can have one or more abstract methods. They cannot be instantiated but can be inherited by other classes. It is for this reason that the constructor in the abstract class is invoked while calling the constructor of the subclass. The subclass can make calls to the constructor in the abstract class explicitly using the `super()` method.

Example:
```java
abstract class Server {
    protected final String name;
   
    public Server(String name){
        this.name = name;
    }
   
    public abstract boolean start();
}

class Tomcat extends Server {
    public Tomcat(String name){
        super(name);
    }
    
    @Override
    public boolean start() {
       System.out.println(this.name + " started successfully");
       return true;
    }
}

public class MainClass {
    public static void main(String args[]) {
       Server server = new Tomcat("Apache Tomcat");
       server.start();
    }
}
/** 
 * OUTPUT:
 * Apache Tomcat started successfully
 */
```