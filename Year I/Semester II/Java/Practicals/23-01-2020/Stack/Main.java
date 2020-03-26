import java.util.Random;

public class Main {
    public static void main(String[] args) {
        int r;
        Stack stack = new Stack(10);
        Random random = new Random(1337);
        System.out.println("Created stack of size 10...");
        System.out.println("Pushing integers onto stack...");
        while (true) {
            r = random.nextInt(100);
            System.out.println("Pushing " + r + "...");
            try {
                stack.push(r);
                System.out.println("Elements in Stack = " + (stack.getTOS() + 1));
            } catch (StackException e) {
                System.err.println(e.getMessage());
                break;
            }
        }
        System.out.println("Popping integers from stack...");
        while (true) {
            System.out.println("Elements in Stack = " + (stack.getTOS() + 1));
            try {
                System.out.println("Popped " + stack.pop() + "...");
            } catch (StackException e) {
                System.err.println(e.getMessage());
                break;
            }
        }
    }
}
