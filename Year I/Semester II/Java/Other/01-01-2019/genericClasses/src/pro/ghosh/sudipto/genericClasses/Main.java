package pro.ghosh.sudipto.genericClasses;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < 10; i++) {
            System.out.println("Pushing " + i);
            stack.push(i);
        }

        stack.print();

        for (int i = 0; i < 10; i++) {
            System.out.println("Popping " + stack.get(i));
        }

        for (int i = 9; i >= 0; i--)
            stack.pop(i);

        stack.print();
    }
}
