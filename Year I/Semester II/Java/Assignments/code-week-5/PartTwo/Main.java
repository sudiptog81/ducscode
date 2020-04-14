
/**
 * Write a program in Java (using try-with-resources functionality) to do the
 * following: 
 *   - open two files "exam1.txt" and "exam2.txt". Accept file names
 *     through command-line arguments. 
 *   - exit the program if any of the two files is
 *     unable to open. 
 *   - append contents of "exam1.txt" to "exam2.txt". 
 *   - re-write contents of "exam2.txt" after removing all white spaces from 
 *     the updated content (without using built-in methods).
 * 
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/
import java.io.*;

public class Main {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java Main <file1> <file2>");
            System.exit(1);
        }

        try (BufferedReader finA = new BufferedReader(new FileReader(args[0]));
                BufferedWriter foutB = new BufferedWriter(new FileWriter(args[1], true))) {
            String s;
            while ((s = finA.readLine()) != null) {
                foutB.newLine();
                foutB.write(s);
                foutB.flush();
            }
            System.out.println("Task 1 Done...");
        } catch (Exception e) {
            System.out.println("Could not open one of the files, exiting...");
            System.exit(-1);
        }

        try (BufferedReader finB = new BufferedReader(new FileReader(args[1]))) {
            String s, o = "";
            while ((s = finB.readLine()) != null) {
                char[] array = s.toCharArray();
                for (int i = 0; i < s.length(); i++)
                    switch (array[i]) {
                        case ' ':
                        case '\t':
                        case '\n':
                        case '\r':
                            break;
                        default:
                            o += array[i];
                            break;
                    }
            }
            try (BufferedWriter foutB = new BufferedWriter(new FileWriter(args[1]))) {
                foutB.write(o);
            }
            System.out.println("Task 2 Done...");
        } catch (Exception e) {
            System.out.println("Could not open one of the files, exiting...");
            System.exit(-1);
        }
    }
}
