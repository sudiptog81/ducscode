Once we have instantiated `BufferedReader` with an instance of `InputStreamReader` having an `InputStream`, we can call predefined methods in the `BufferedReader` class to read characters and strings from the `InputStream`.

 - To read characters, we use the `read()` method of the `BufferedReader` class to read a single character as an `int` which can then be type-casted into a `char` or `read(char[] buffer, int offset, int length)` method to read a number of characters into a portion of an array.

 - To read strings, we use the `readLine()` method to read one line of characters at a time from the keyboard and store it as a `String`.

Use of the various methods mentioned above can be demonstrated by running the program given below:

```java
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        // Instantating BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Reading String
        String str;
        str = br.readLine();
        
        // Reading Characters to an Array
        char[] buffer = new char[3];
        br.read(buffer, 0, 3);

        // Reading a Single Character
        char c;
        c = (char) br.read();

        // Generate Output
        System.out.println(str);
        System.out.println(buffer);
        System.out.println(c);

        // Closing BufferedReader
        br.close();
    }
}
```

```txt
hello, world
hello
hello, world
hel
l
```

