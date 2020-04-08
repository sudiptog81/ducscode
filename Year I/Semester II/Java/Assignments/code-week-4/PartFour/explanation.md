In order to handle console output using the `PrintWriter` class, one has to instantiate an instance of the class and use one of the many methods defined in the class to achieve the same. This class does not contain methods for writing raw bytes, for which a program should use unencoded byte streams, but only handles character-output streams. 

The `PrintWriter` class has `PrintWriter(OutputStream outputStrean, boolean autoFlush)` as one of its constructors. Here, `outputStrean` is an object of `OutputStream` class and `autoFlush` is a `boolean` value which controls the automatic line flushing behaviour of `outputStream`. If `autoFlush` is `true`, `outputStream` is flushed whenever `print`, `printf` or `println` methods are invoked. Otherwise, an invocation of the `flush` method is required to actually flush the stream.

Methods in this class never throw I/O exceptions, although some of its constructors may throw such an exception.

Example Program:
```java
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
```