/**
 * Using Swing, write a program to create two buttons named "Red"  
 * and "Blue". When a button is pressed the background colour should  
 * be set to the colour named by the button’s label.
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class Main {
    JButton btnRed, btnBlue;
    Main() {
        JFrame f = new JFrame("Swing Buttons");
        btnRed = new JButton("Red");
        btnRed.setBounds(16, 20, 250, 30);
        btnRed.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                f.getContentPane().setBackground(Color.RED);
            }
        });
        f.add(btnRed);
        btnBlue = new JButton("Blue");
        btnBlue.setBounds(16, 65, 250, 30);
        btnBlue.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                f.getContentPane().setBackground(Color.BLUE);
            }
        });
        f.add(btnBlue);
        f.setSize(300, 160);
        f.setLayout(null);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Main();
            }
        });
    }
}

