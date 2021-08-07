package pro.ghosh.sudipto.factorial;

public class Driver {
    public static void main(String[] args) {
        long start, end, factorial;

        // Time Iterative Version
        start = System.nanoTime();
        factorial = Factorial.findIteratively(12);
        end = System.nanoTime();
        System.out.print("Factorial of 12 by Iteration: ");
        System.out.print(factorial + "\n");
        System.out.println(
                String.format(
                        "Execution finished in %.5f ms.",
                        (end - start) / 10e6
                )
        );

        System.out.println();

        // Time Recursive Version
        start = System.nanoTime();
        factorial = Factorial.findRecursively(12);
        end = System.nanoTime();
        System.out.print("Factorial of 12 by Recursion: ");
        System.out.print(factorial + "\n");
        System.out.println(
                String.format(
                        "Execution finished in %.5f ms.",
                        (end - start) / 10e6
                )
        );
    }
}
