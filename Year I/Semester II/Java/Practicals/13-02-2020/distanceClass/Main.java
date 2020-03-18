import java.io.*;

class Main
{
    public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	    System.out.print("Enter feet: ");
	    int a = Integer.parseInt(br.readLine());

	    System.out.print("Enter inches: ");
	    int b = Integer.parseInt(br.readLine());

	    Distance d = new Distance(a, b);

	    d.display();
    }
}
