import java.io.*;

public class Main {
    static int n;
    static boolean[] primes;
    final static int constraint = 100000;

    /**
     * Prime Sieve Implementation: O(n log log n)
     * 
     * @see https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
     */
    static void prime_sieve_init() {
        // dynamically allocate memory to store prime numbers
        primes = new boolean[constraint + 1];

        // explicitly mark all numbers as prime
        for (int i = 0; i <= constraint; i++) {
            primes[i] = true;
        }

        // for i = 2, 3, 4, ..., not exceeding √n
        for (int i = 2; i * i <= constraint; i++) {
            // if the number is prime
            if (primes[i] == true) {
                // mark all the multiples of i as not prime
                for (int j = i * i; j <= constraint; j += i) {
                    primes[j] = false;
                }
            }
        }

        // handle edge cases
        primes[1] = primes[0] = false;
    }

    // Check if the number is Prime: O(1)
    static boolean checkPrime(int n) {
        return primes[n];
    }

    // Driver Code
    public static void main(String[] args) throws IOException {
        // initialize an array of prime numbers
        prime_sieve_init();

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
        if (checkPrime(n) == true)
            System.out.println(n + " is a prime number.");
        else
            System.out.println(n + " is not a prime number.");
    }
}