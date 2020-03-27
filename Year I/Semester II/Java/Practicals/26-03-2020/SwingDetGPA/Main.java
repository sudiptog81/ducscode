
/**
 * Using Swing, write a program to create two buttons labelled 
 * ‘A’ and ‘B’. When button ‘A’ is pressed, it displays your 
 * personal information (Name, Course, Roll No, College) and 
 * when button ‘B’ is pressed, it displays your CGPA in 
 * previous semester.
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Main implements ActionListener {
    JButton btnInfo, btnCGPA;

    Main() {
        JFrame f = new JFrame("Student Details");
        btnInfo = new JButton("A");
        btnInfo.setBounds(18, 100, 450, 100);
        btnInfo.addActionListener(this);
        f.add(btnInfo);
        btnCGPA = new JButton("B");
        btnCGPA.setBounds(18, 270, 450, 100);
        btnCGPA.addActionListener(this);
        f.add(btnCGPA);
        f.setSize(500, 500);
        f.setLayout(null);
        f.setVisible(true);
        f.setLocationRelativeTo(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Main();
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnInfo) {
            new Information("SUDIPTO GHOSH", "BSc (Hons) Computer Science", "19/78003", "ARSD College");
        } else if (e.getSource() == btnCGPA) {
            new CGPA("9.73");
        }
    }
}
