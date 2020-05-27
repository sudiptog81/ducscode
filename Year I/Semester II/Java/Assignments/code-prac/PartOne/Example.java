class Example {
  private int val;

  // Default Constructor
  Example() {
    val = 0;
  }

  // Paramterized Constructor
  Example(int val) {
    this.val = val;
  }

  int getVal() {
    return val;
  }

  int method(int n) {
    return n;
  }

  // Method overloading with different number of parameters
  int method(int n, int m) {
    return n + m;
  }

  // Method Overloading with type of parameters
  int method(char c) {
    return (int) (c);
  }

  // Method overloading with different sequence of parameters
  int method(char c, int m) {
    return (int) (c) + m;
  }

  int method(int m, char c) {
    return (int) (c) - m;
  }

  public static void main(String[] args) {
    Example e1 = new Example();
    Example e2 = new Example(2);
    System.out.println(e1.getVal());
    System.out.println(e2.getVal());
    System.out.println(e1.method(10));
    System.out.println(e1.method(10, 29));
    System.out.println(e1.method('A'));
    System.out.println(e1.method('B', 10));
    System.out.println(e1.method(10, 'C'));
  }
}
