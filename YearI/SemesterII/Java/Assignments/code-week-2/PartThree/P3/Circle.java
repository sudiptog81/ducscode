package P3;

import java.io.*;

import P1.*;

public class Circle extends Shape {
    private double radius;

    protected void getData() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter Radius of Circle: ");
        radius = Double.parseDouble(br.readLine());
    }

    public double area() throws IOException {
        getData();
        return Math.PI * radius * radius;
    }
}