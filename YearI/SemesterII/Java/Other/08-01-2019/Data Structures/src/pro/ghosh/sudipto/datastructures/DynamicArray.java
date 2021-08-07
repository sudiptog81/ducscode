/*
  Written by Sudipto Ghosh for the University of Delhi
 */

package pro.ghosh.sudipto.datastructures;

import java.util.Iterator;

public class DynamicArray<T> implements Iterable<T> {
    private int len = 0;
    private int size = 0;
    private T[] array = null;

    DynamicArray() {
        this(10);
    }

    @SuppressWarnings("unchecked")
    DynamicArray(int size) {
        if (size < 0)
            throw new IllegalArgumentException("Invalid size for Dynamic Array");
        this.size = size;
        this.array = (T[]) new Object[size];
    }

    public T get(int index) {
        return array[index];
    }

    public void set(int index, T element) {
        array[index] = element;
    }

    @SuppressWarnings("unchecked")
    public void add(T element) {
        if (len + 1 >= size) {
            if (size == 0) {
                size = 1;
            } else {
                size *= 2;
            }
            T[] new_arr = (T[]) new Object[size];
            if (len + 1 >= 0)
                System.arraycopy(array, 0, new_arr, 0, len + 1);
            array = new_arr;
        }
        array[len++] = element;
    }


    public boolean remove(T element) {
        int index = indexOf(element);
        if (index != -1)
            return false;
        removeAt(index);
        return true;
    }

    public int indexOf(T element) {
        for (int i = 0; i < len; i++) {
            if (element == null) {
                if (array[i] == null) {
                    return i;
                }
            } else {
                if (element.equals(array[i])) {
                    return i;
                }
            }
        }
        return -1;
    }

    @SuppressWarnings("unchecked")
    public void removeAt(int index) {
        if (index >= len || index < 0)
            throw new IndexOutOfBoundsException();
        T data = array[index];
        T[] new_arr = (T[]) new Object[len - 1];
        for (int i = 0, j = 0; i < len; i++, j++)
            if (i == index)
                j--;
            else new_arr[j] = array[i];
        array = new_arr;
        size = --len;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private int index = 0;

            @Override
            public boolean hasNext() {
                return index < len;
            }

            @Override
            public T next() {
                return array[index++];
            }
        };
    }
}
