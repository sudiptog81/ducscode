package pro.ghosh.sudipto.searchingAlgos;

import java.util.Scanner;

public class Main {
    static int linearSearch(int[] array, int ele) {
        for (int i = 0; i < array.length; i++) {
            if (ele == array[i]) {
                System.out.println("Element found at index " + i + ".");
                return i;
            }
        }
        System.out.println("Element not found.");
        return -1;
    }

    static int binarySearch(int[] array, int ele) {
        int mid = 0, first = 0, last = array.length;
        while (first <= last) {
            mid = (first + last) / 2;
            if (ele > array[mid]) {
                first = mid + 1;
            } else if (ele < array[mid]) {
                last = mid - 1;
            } else {
                System.out.println("Element found at index " + mid + ".");
                return mid;
            }
        }
        System.out.println("Element not found.");
        return -1;
    }

    public static void main(String[] args) {
        long start, end;

        // Declare the Array to Search
        int[] array = {
                -9911, -9637, -9304, -9204, -9009,
                -8693, -8685, -8608, -8438, -8203,
                -7939, -6614, -6024, -5934, -5814,
                -5647, -5602, -5321, -4776, -4746,
                -4416, -4140, -3816, -3684, -3550,
                -3525, -3386, -3240, -3190, -3004,
                -2943, -2647, -2439, -2201, -1849,
                -1712, -1656, -1558, -1441, -1271,
                -1248, -1016, -638, -577, -390,
                130, 322, 393, 592, 654, 1199, 1434,
                1491, 2279, 2347, 2350, 2434, 2671,
                2693, 2804, 2805, 2851, 2954, 3479,
                3481, 3754, 3996, 4428, 4478, 4478,
                4574, 4602, 4677, 5037, 5204, 5290,
                5500, 5894, 6196, 6407, 6712, 7055,
                7375, 7608, 7757, 7764, 7804, 7821,
                7829, 7887, 8386, 8434, 8526, 8544,
                8557, 8647, 8678, 8719, 9451, 9829
        };

        // Prompt for Element to Search
        System.out.print("Array contains " + array.length + " elements.\n");
        System.out.print("Element to Search: ");
        Scanner s = new Scanner(System.in);
        int element = s.nextInt();

        System.out.println();

        // Time the Linear Search Method
        System.out.println("Linear Search:");
        start = System.nanoTime();
        linearSearch(array, element);
        end = System.nanoTime();
        System.out.print(String.format("Search completed in %.5f ms.\n",
                (end - start) / 10e6));

        System.out.println();

        // Time the Binary Search Method
        System.out.println("Binary Search:");
        start = System.nanoTime();
        binarySearch(array, element);
        end = System.nanoTime();
        System.out.print(String.format("Search completed in %.5f ms.\n",
                (end - start) / 10e6));
    }
}
