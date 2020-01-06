package pro.ghosh.sudipto.genericClasses;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class StackTest {
    final private Stack<String> stack;

    StackTest() {
        this.stack = new Stack<>(String.class, 2);
    }

    @Test
    void push() {
        Assertions.assertThrows(StackException.class, () -> {
            this.stack.push("A");
            this.stack.push("B");
            this.stack.push("C");
        }, "filled stack should throw Stack Overflow exception on pushing");
    }

    @Test
    void pop() {
        Assertions.assertThrows(StackException.class, () -> {
            this.stack.pop();
            this.stack.pop();
            this.stack.pop();
        }, "empty stack should throw Stack Underflow exception on popping");
    }

    @Test
    void getTOS() {
        Assertions.assertEquals(-1, this.stack.getTOS(), "empty stack should have tos of -1");
    }
}