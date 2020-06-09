import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int num = 0, rem = 0;
        String ans = "", finalAns = "";
        Scanner sc = new Scanner(System.in);

        System.out.print("Decimal: ");

        num = sc.nextInt();

        // Calculate remainders and append to answer
        do {
            rem = num % 2;
            num /= 2;
            ans += rem;
        } while (num != 0);

        // Reverse the answer string to get finalAns
        for (int i = ans.length() - 1; i >= 0; i--) {
            finalAns = finalAns + ans.charAt(i);
        }

        System.out.println("Binary: " + finalAns);

        sc.close();
    }
}