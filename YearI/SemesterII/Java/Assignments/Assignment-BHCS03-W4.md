# Assignment - Week 4

## Examiner
Department of Computer Science, University of Delhi

## Part One
What will be the output (along with explanation) of the given program?

```java
import java.io.*;
class Chararrayinput {
    public static void main(String[] args) {
        String obj = "abcdef";
        int length = obj.length();
        char c[] = new char[length];
        obj.getChars(0, length, c, 0);
        CharArrayReader input1 = new CharArrayReader(c);
        CharArrayReader input2 = new CharArrayReader(c, 0, 3);
        int i;
        try {
            while ((i = input2.read()) != -1) {
                System.out.print((char) i);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

## Part Two
Write a program that copies content of one file to another. Pass the names of the files through command-line arguments.

## Part Three
Write a program to read a file and display only those lines that have the first two characters as `//` (Use `try -with-resources`).

## Part Four
How do you handle console output using `PrintWriter` class?

## Part Five
How do you read (1) characters (2) a string , using the `BufferedReader` class?

## Part Six
Write the names and meanings of all stream classes  discussed in the reference book.

---

Updated on April 06, 2020