import java.io.*;

/**
 * To print the reverse of a number
 * 
 * @author Sudipto Ghosh
 */
class Main {
    public static void main(String[] args) throws IOException {
        int sum = 0, rem, n;
        String s;

        System.out.print("Enter a number: ");

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine();
        n = Integer.parseInt(s);

        while (n != 0) {
            rem = n % 10;
            sum = sum * 10 + rem;
            n /= 10;
        }

        System.out.println("Reversed Number: " + sum);
    }
}