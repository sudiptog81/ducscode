/**** StackException.java ****/
public class StackException extends Exception {
    final private String message;

    public StackException(String message) {
        this.message = message;
    }

    @Override
    public String getMessage() {
        return this.message;
    }
}
