
/**
 * Write a program that copies content of one file to another.
 * Pass the names of the files through command-line arguments.
 * 
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Copy.java ****/
import java.io.*;

public class Copy {
    public static void main(String[] args) throws Exception {
        if (args.length != 2) {
            System.err.println("Usage: java Copy <src> <dest>");
        } else {
            int i;
            FileInputStream fin = new FileInputStream(args[0]);
            FileOutputStream fout = new FileOutputStream(args[1]);
            while ((i = fin.read()) != -1) {
                fout.write(i);
            }
            fin.close();
            fout.close();
            System.out.println("Copied contents of " + args[0] + " to " + args[1]);
        }
    }
}