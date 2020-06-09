package pro.ghosh.sudipto.personInterface;

import java.util.Scanner;

public class Faculty implements Person {
    String name;
    int facultyId;
    String department;

    String getName() {
        return this.name;
    }

    int getFacultyId() {
        return this.facultyId;
    }

    String getDepartment() {
        return this.department;
    }

    void setName(String name) {
        this.name = name;
    }

    void setFacultyId(int facultyId) {
        this.facultyId = facultyId;
    }

    void setDepartment(String department) {
        this.department = department;
    }

    public void display() {
        System.out.println("FACULTY\n-------");
        System.out.println("Name: " + this.getName());
        System.out.println("Department: " + this.getDepartment());
        System.out.println("Faculty ID: " + this.getFacultyId());
    }

    public void register() {
        Scanner sc = new Scanner(System.in);
        System.out.println("REGISTERING FACULTY...");
        System.out.print("Enter Name: ");
        this.setName(sc.next());
        System.out.print("Enter Department: ");
        this.setDepartment(sc.next());
        System.out.print("Enter Faculty ID: ");
        this.setFacultyId(sc.nextInt());
    }
}
