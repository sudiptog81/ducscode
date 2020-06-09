import java.io.*;

class Main {
    private static int[] array;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the size of the array: ");
        int size = Integer.parseInt(br.readLine());
        array = new int[size];

        for (int i = 0; i < size; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            array[i] = Integer.parseInt(br.readLine());
        }

        System.out.print("Array: ");
        for (int i : array)
            System.out.print(i + " ");
    }
}