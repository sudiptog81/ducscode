/**** UnderAge.java ****/
public class UnderAge extends Exception {
    final private int age;

    public UnderAge(int age) {
        this.age = age;
    }

    @Override
    public String getMessage() {
        return "UnderAge: " + age + " is less than 18";
    }
}