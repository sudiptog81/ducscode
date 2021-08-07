package pro.ghosh.sudipto.personInterface;

import java.util.Scanner;

public class Student implements Person {
   int rollNo;
   String name;
   String course;

   String getName() {
      return this.name;
   }

   int getRollNo() {
      return this.rollNo;
   }

   String getCourse() {
      return this.course;
   }

   void setName(String name) {
      this.name = name;
   }

   void setRollNo(int rollNo) {
      this.rollNo = rollNo;
   }

   void setCourse(String course) {
      this.course = course;
   }

   public void display() {
      System.out.println("STUDENT\n-------");
      System.out.println("Name: " + this.getName());
      System.out.println("Course: " + this.getCourse());
      System.out.println("Roll No.: " + this.getRollNo());
   }

   public void register() {
      Scanner sc = new Scanner(System.in);
      System.out.println("REGISTERING STUDENT...");
      System.out.print("Enter Name: ");
      this.setName(sc.next());
      System.out.print("Enter Course: ");
      this.setCourse(sc.next());
      System.out.print("Enter Roll No.: ");
      this.setRollNo(sc.nextInt());
   }
}
