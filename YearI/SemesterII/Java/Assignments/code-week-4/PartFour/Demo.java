import java.io.*;

public class Demo {
    public static void main(String[] args) {
        PrintWriter p;

        // PrintWriter Instance w/o Automatic Line Flusing
        p = new PrintWriter(System.out);
        p.println("Hi");
        p.flush();

        // PrintWriter Instance w/ Automatic Line Flusing
        p = new PrintWriter(System.out, true);
        p.println("Hi");
    }
}