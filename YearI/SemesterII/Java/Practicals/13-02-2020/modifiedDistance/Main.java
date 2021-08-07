import java.io.*;

class Main
{
    public static void main(String[] args) throws Exception 	{
	Distance d1, d2, d3, d4;
	d1 = new Distance(1, 13);
	d1.display();
	d2 = new Distance(0, 48);
	d3 = d2;
	d3.display();
	d3 = new Distance(d1);
	d3.display();
    }
}