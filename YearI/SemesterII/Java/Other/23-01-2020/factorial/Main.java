import java.io.*;

/**
 * To print the factorial of a number
 * 
 * @author Sudipto Ghosh
 */
class Main {
    public static void main(String[] args) throws IOException {
        int f = 1, n;
        String s;
        float i;

        System.out.print("Enter an integer: ");

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        s = br.readLine();
        n = Integer.parseInt(s);

        for (i = n; i > 0; i--) {
            f *= i;
        }

        System.out.println("Factorial = " + f);
    }
}