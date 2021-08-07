class FuncOverloading {
    String one(byte a, byte b) {
        System.out.println("byte-byte version");
        return "" + a + " " + b;
    }

    String one(short a, short b) {
        System.out.println("short-short version");
        return "" + a + " " + b;
    }

    String one(int a, int b) {
        System.out.println("int-int version");
        return "" + a + " " + b;
    }

    String one(long a, long b) {
        System.out.println("long-long version");
        return "" + a + " " + b;
    }

    String one(float a, float b) {
        System.out.println("float-float version");
        return "" + a + " " + b;
    }

    String one(double a, double b) {
        System.out.println("double-double version");
        return "" + a + " " + b;
    }

    String one(char a, char b) {
        System.out.println("char-char version");
        return "" + a + " " + b;
    }
}
