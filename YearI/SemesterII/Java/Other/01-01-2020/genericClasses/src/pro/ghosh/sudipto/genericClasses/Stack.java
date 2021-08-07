package pro.ghosh.sudipto.genericClasses;

/**
 * Implementation of the Stack Data Structure using Arrays in Java
 *
 * @param <T> Class of Generic Elements
 * @author sudipto@ghosh.pro University of Delhi
 * @see java.util.LinkedList
 */
public class Stack<T> {
    /**
     * Top of the Stack
     */
    private int tos;

    /**
     * Array of Generic Elements
     */
    private Object[] array;

    /**
     * Size of the Stack
     */
    final private int size;

    /**
     * Class of Generic Elements
     */
    final private String className;

    /**
     * Public Constructor for Stack Objects
     *
     * @param tClass Class of Generic Elements
     * @param size   Size of the Stack
     */
    public Stack(Class<T> tClass, int size) {
        this.tos = -1;
        this.size = size;
        this.array = new Object[this.size];
        this.className = tClass.getSimpleName();
    }

    /**
     * Push an element to the top of the stack
     *
     * @param e Element to be pushed
     * @throws StackException Stack Overflow
     */
    public void push(T e) throws StackException {
        if (tos == size - 1)
            throw new StackException("Stack Overflow: could not push " + e);
        else
            this.array[++this.tos] = e;
    }

    /**
     * Pop an element from the stack
     *
     * @return Object on top of the stack
     * @throws StackException Stack Underflow
     */
    public Object pop() throws StackException {
        if (this.tos < 0) {
            throw new StackException("Stack Underflow: could not pop anymore");
        } else
            return this.array[this.tos--];
    }

    /**
     * Index of the element at the top of the stack
     *
     * @return Index of Generic Element
     */
    public int getTOS() {
        return this.tos;
    }

    /**
     * Representation of Stack Object
     *
     * @return String Representation
     */
    @Override
    public String toString() {
        return "Stack<" + this.className + ", " + this.size + ">";
    }
}