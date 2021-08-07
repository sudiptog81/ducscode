package pro.ghosh.sudipto.genericClasses;

import java.util.Random;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Random random = new Random(1337);
        Stack<Integer> stack = new Stack<>(Integer.class, 10);

        System.out.println("Created " + stack + "...");
        System.out.println("Pushing integers onto stack...");
        while (true) {
            int r = random.nextInt(100);
            System.out.println("Pushing " + r + "...");
            try {
                stack.push(r);
                System.out.println("TOS = " + stack.getTOS());
            } catch (StackException e) {
                System.err.println(e.getMessage());
                break;
            }
        }

        Thread.sleep(500);

        System.out.println("Popping integers from stack...");
        while (true) {
            System.out.println("TOS = " + stack.getTOS());
            try {
                System.out.println("Popped " + stack.pop() + "...");
            } catch (StackException e) {
                System.err.println(e.getMessage());
                break;
            }
        }
    }
}
