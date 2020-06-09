import java.io.*;

/**
 * To print the sum of the series 1 - 2 + 3 - 4 + ... + n
 * 
 * @author Sudipto Ghosh
 */
class Main {
	public static void main(String[] args) throws IOException {
		int i, n, t = 0;
		String s;

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the value of n: ");

		s = br.readLine();
		n = Integer.parseInt(s);

		for (i = 1; i <= n; i++) {
			if (i % 2 == 0) {
				t -= i;
			} else {
				t += i;
			}
		}

		System.out.println("Total = " + t);
	}
}
