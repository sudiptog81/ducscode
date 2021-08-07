import java.io.*;

/**
 * To generate n prime numbers
 * 
 * @author Sudipto Ghosh
 */
class Main {
    public static void main(String[] args) throws IOException {
        int i, j, c = 0, n;
        String s;

        System.out.print("Enter value for n: ");

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine();
        n = Integer.parseInt(s);

        System.out.println("Prime Numbers upto " + n + ":");
        for (j = 2; j <= n; j++) {
            c = 0;
            for (i = 1; i <= j; i++) {
                if (j % i == 0)
                    c++;
            }
            if (c == 2)
                System.out.print(j + " ");
        }

        System.out.println();
    }
}