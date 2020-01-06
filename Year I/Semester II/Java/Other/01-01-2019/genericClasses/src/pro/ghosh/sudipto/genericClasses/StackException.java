package pro.ghosh.sudipto.genericClasses;

public class StackException extends Throwable {
    final private String message;

    public StackException(String message) {
        this.message = message;
    }

    @Override
    public String getMessage() {
        return this.message;
    }
}
