/** package2/A.java **/
package package2;

public class A {
  public void printpubA() {
    printproA(); // works
  }

  protected void printproA() {
    printdefA(); // works
  }

  private void printpriA() {
    System.out.println('A');
  }

  void printdefA() {
    printpriA(); // works
  }

  public void printpubB() {
    B b = new B();
    b.printdefB();
  }

  public static void main(String[] args) {
    A a = new A();
    a.printpriA();
  }
}