/**
 * To find the sum of any number of integers entered as command-line arguments
 * 
 * @author Sudipto Ghosh
 */
class Main {
    public static void main(String[] args) {
        int num, sum = 0;

        System.out.print("CLI Arguments are: ");
        for (int i = 0; i < args.length; i++) {
            System.out.print(args[i] + " ");

            num = Integer.parseInt(args[i]);
            sum += num;
        }

        System.out.println("\nSum of elements is " + sum);
    }
}