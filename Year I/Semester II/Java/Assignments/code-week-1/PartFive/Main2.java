import java.io.*;

public class Main2 {
    static int n;

    // Check if the number is Prime
    static boolean checkPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    // Driver Code
    public static void main(String[] args) throws IOException {
        // check for presence of command line arguments
        if (args.length != 0) {
            // get input from the first command line argument
            n = Integer.parseInt(args[0]);
        } else {
            // prompt the user for input if no cli arg found
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter an integer: ");
            n = Integer.parseInt(br.readLine());
        }

        // print the result to the console
        System.out.println(n + " is " + (checkPrime(n) == true ? "" : "not") + " a prime number.");
    }
}