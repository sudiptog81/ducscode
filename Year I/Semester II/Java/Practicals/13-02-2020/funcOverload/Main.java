class Main
{
    public static void main(String[] args) {
        int i = 1000;
	    short s = 108;
        byte b = 127;
	    long l = 1324343123123314l;
	    float f = 123.0f;
	    double d = 2312.34d;
	    char c = 'c';

    	FuncOverloading o = new FuncOverloading();

	    // byte -> int -> short -> long
        System.out.println("byte -> int -> short -> long\n-------------------------------");
        System.out.println(o.one(b, b));
        System.out.println(o.one(b, i));
        System.out.println(o.one(b, s));
        System.out.println(o.one(b, l));
        System.out.println();

	    // short -> int -> long
        System.out.println("short -> int -> long\n-------------------------------");
        System.out.println(o.one(s, s));
        System.out.println(o.one(s, i));
        System.out.println(o.one(s, l));
        System.out.println();

	    // int -> long -> float -> double
        System.out.println("int -> long -> float -> double\n-------------------------------");
        System.out.println(o.one(i, i));
        System.out.println(o.one(i, l));
        System.out.println(o.one(i, f));
        System.out.println(o.one(i, d));
        System.out.println();

	    // float -> double
        System.out.println("float -> double\n-------------------------------");
    	System.out.println(o.one(f, f));
        System.out.println(o.one(f, d));
        System.out.println();

	    // long -> float -> double
        System.out.println("long -> float -> double\n-------------------------------");
    	System.out.println(o.one(l, l));
        System.out.println(o.one(l, f));
        System.out.println(o.one(l, d));
        System.out.println();

	    // char -> int
        System.out.println("char -> int\n-------------------------------");
    	System.out.println(o.one(c, c));
  	    System.out.println(o.one(c, i));
        System.out.println();
    }
}
