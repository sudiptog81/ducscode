
/**
 * Using AWT, write a program to create two buttons labelled 
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

public class Main extends Frame implements MouseListener {
    Button btnInfo, btnCGPA;

    Main() {
        super("Student Details");

        btnInfo = new Button("A");
        btnInfo.setBounds(25, 125, 450, 100);
        btnInfo.addMouseListener(this);
        this.add(btnInfo);

        btnCGPA = new Button("B");
        btnCGPA.setBounds(25, 300, 450, 100);
        btnCGPA.addMouseListener(this);
        this.add(btnCGPA);

        this.setSize(500, 500);
        this.setLayout(null);
        this.setVisible(true);
        this.setLocationRelativeTo(null);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    public static void main(String[] args) {
        new Main();
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        if (e.getSource() == btnInfo) {
            new Information("SUDIPTO GHOSH", "BSc (Hons) Computer Science", "19/78003", "ARSD College");
        } else if (e.getSource() == btnCGPA) {
            new CGPA("9.73");
        }
    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
}