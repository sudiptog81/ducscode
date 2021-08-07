/*
 * Written by Sudipto Ghosh for the University of Delhi
 */

package pro.ghosh.sudipto.datastructures;

public class Driver {
    public static void main(String[] args) {
        DynamicArray<Integer> array = new DynamicArray<>();
        array.add(1);
        array.add(2);
        System.out.println("" + array.get(0));
        array.removeAt(0);
        System.out.println("" + array.get(0));
   }
}
