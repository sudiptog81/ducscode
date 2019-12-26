package pro.ghosh.sudipto.sortingAlgos;

public class Main {
    /**
     * Displays the contents of an Array
     *
     * @param array Integer[]
     */
    static void display(int[] array) {
        for (int i : array) {
            System.out.print(i + " ");
        }
    }

    /**
     * Performs Bubble Sort on an Integer Array
     *
     * @param array Integer[]
     */
    static void bubbleSort(int[] array) {
        for (int i = 0, temp; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    /**
     * Performs Insertion Sort on an Integer array
     *
     * @param array Integer[]
     */
    static void insertionSort(int[] array) {
        for (int i = 1, j, key; i < array.length; ++i) {
            key = array[i];
            j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j--];
            }
            array[j + 1] = key;
        }
    }

    /**
     * Performs Selection Sort on an Integer Array
     *
     * @param array Integer[]
     */
    static void selectionSort(int[] array) {
        for (int i = 0, min, temp; i < array.length - 1; i++) {
            min = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[i] > array[j]) {
                    min = j;
                }
            }
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }

    public static void main(String[] args) {
        long start, end;

        int[] array = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

        System.out.print("Array: ");
        display(array);
        System.out.println();

        System.out.print("Bubble Sort: ");
        start = System.nanoTime();
        bubbleSort(array);
        end = System.nanoTime();
        System.out.println(
                String.format("Sorting took %.5f ms.", (end - start) / 10e6)
        );

        System.out.print("Selection Sort: ");
        start = System.nanoTime();
        selectionSort(array);
        end = System.nanoTime();
        System.out.println(
                String.format("Sorting took %.5f ms.", (end - start) / 10e6)
        );

        System.out.print("Insertion Sort: ");
        start = System.nanoTime();
        insertionSort(array);
        end = System.nanoTime();
        System.out.println(
                String.format("Sorting took %.5f ms.", (end - start) / 10e6)
        );
    }
}
