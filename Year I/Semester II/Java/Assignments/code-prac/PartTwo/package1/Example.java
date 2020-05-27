/** package1/Example.java **/
package package1;

import package2.*;

class Example {
  public static void main(String[] args) {
    A a = new A();
    a.printpubA(); // works
    // a.printproA(); // A::printproA() not accessible to package1.Example
    // a.printpriA(); // A::printpriA() not accessible to package1.Example
    // a.printdefA(); // A::printdefA() not accessible to package1.Example

    // B b = new B(); // class B is not accessible to package1.Example
    // b.printdefB(); // B::printdefB() not accessible to package1.Example
    a.printpubB(); // works
  }
}