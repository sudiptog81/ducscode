package pro.ghosh.sudipto.personInterface;

import java.util.Scanner;

public class Driver {
    public static void main(String[] args) {
        int studentsCount, facultyCount;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Number of Students to Register: ");
        studentsCount = scanner.nextInt();
        Student[] studentArray = new Student[studentsCount];
        for (int i = 0; i < studentsCount; i++) {
            studentArray[i] = new Student();
            studentArray[i].register();
            System.out.println();
        }

        System.out.println("Registration of Students successful...");
        for (Student s : studentArray) {
            s.display();
            System.out.println();
        }

        System.out.print("Number of Faculties to Register: ");
        facultyCount = scanner.nextInt();
        Faculty[] facultyArray = new Faculty[facultyCount];
        for (int i = 0; i < facultyCount; i++) {
            facultyArray[i] = new Faculty();
            facultyArray[i].register();
            System.out.println();
        }

        System.out.println("Registration of Faculties successful...");
        for (Faculty f : facultyArray) {
            f.display();
            System.out.println();
        }
    }
}
