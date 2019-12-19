package pro.ghosh.sudipto.MatrixOps;

public class MatrixException extends Throwable {
    @Override
    public String getMessage() {
        return "Matrix dimensions not correct.\n";
    }
}
