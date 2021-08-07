
/**
 * Using AWT, write a program to create two buttons named "Red" and 
 * "Blue". When a button is pressed the background colour should be 
 * set to the colour named by the button’s label.
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/
import java.awt.*;
import java.awt.event.*;

public class Main extends Frame implements MouseListener {
    Button btnRed, btnBlue;

    Main() {
        super("AWT Buttons");

        btnRed = new Button("Red");
        btnRed.setBounds(25, 50, 250, 30);
        btnRed.addMouseListener(this);
        this.add(btnRed);

        btnBlue = new Button("Blue");
        btnBlue.setBounds(25, 100, 250, 30);
        btnBlue.addMouseListener(this);
        this.add(btnBlue);

        this.setSize(300, 160);
        this.setLayout(null);
        this.setVisible(true);
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
        if (e.getSource() == btnRed) {
            this.setBackground(Color.RED);
        } else if (e.getSource() == btnBlue) {
            this.setBackground(Color.BLUE);
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