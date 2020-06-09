package pro.ghosh.sudipto.factorial;

public class Factorial {
    static long findIteratively(long n) {
        long product = 1;
        for (long i = n; i > 0; i--) {
            product = product * i;
        }
        return product;
    }

    static long findRecursively(long n) {
        return n > 0 ? n * findRecursively(n - 1) : 1;
    }
}
