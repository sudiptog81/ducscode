package pro.ghosh.sudipto.genericClasses;

import java.util.ArrayList;

public class Stack<T> {
    String className;
    ArrayList<T> array;

    Stack() {
        this.array = new ArrayList<T>(100);
    }

    void push(T e) {
        this.array.add(e);
        this.className = e.getClass().getName();
    }

    T get(int i) {
        return this.array.get(i);
    }

    void pop(int i) {
        this.array.remove(i);
    }

    int length() {
        return this.array.size();
    }

    void print() {
        System.out.print("Stack<" + this.className + "> (" + this.length() + "): [ ");
        for (T e : this.array)
            System.out.print(e + " ");
        System.out.print("]\n");
    }
}