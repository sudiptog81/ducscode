import java.io.*;

/**
 * To print the sum of series 1/1 + 1/2 + 1/3 + ... 1/n
 *
 * @author Sudipto Ghosh
 */
public class Main {

    public static void main(String[] args) throws IOException {
        int n;
        String s;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        float i, t = 0;

        System.out.print("Enter the value of n: ");

        s = br.readLine();
        n = Integer.parseInt(s);

        for (i = 1; i <= n; i++) {
            t += 1 / i;
        }

        System.out.println("Total = " + t);
    }
}