abstract class Parent
{
    abstract void message();
}

class FirstSubClass extends Parent
{
    void message() {
        System.out.println("This is first subclass");
    }
}

class SecondSubClass extends Parent
{
    void message() {
        System.out.println("This is second subclass");
    }
}

public class Main
{
    public static void main(String[] args) {
        FirstSubClass f = new FirstSubClass();
        SecondSubClass s = new SecondSubClass();

        f.message();
        s.message();
    }
}
