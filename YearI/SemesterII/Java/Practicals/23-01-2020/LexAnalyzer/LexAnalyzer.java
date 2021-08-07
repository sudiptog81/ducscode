
/**
 * Write a program to read a file and display only those lines that have the
 * first two characters as '//'.
 * 
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** LexAnalyzer.java ****/
import java.io.*;

// Sudipto Ghosh

public class LexAnalyzer {
	static boolean analyze(String line) {
		if (line.length() >= 2)
			return line.substring(0, 2).equals("//");
		return false;
	}

	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("Usage: java LexAnalyzer <file>");
		} else {
			try {
				String str;
				BufferedReader br = new BufferedReader(new FileReader(args[0]));
				while ((str = br.readLine()) != null) {
					str = str.trim();
					if (analyze(str)) {
						System.out.println(str);
					}
				}
				br.close();
			} catch (Exception e) {
				System.err.println(e.getMessage());
			}
		}
	}
}

// This is a line of comment
