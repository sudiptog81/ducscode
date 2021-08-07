/** package2/B.java **/
package package2;

class B {
  void printdefB() {
    System.out.println('B');
  }

  public static void main(String[] args) {
    A a = new A(); // works
    a.printpubA(); // works
    a.printproA(); // works
    // a.printpriA(); // A::printpriA() not accessible to package2.B
    a.printdefA(); // works
  }
}