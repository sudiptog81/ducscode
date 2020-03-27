/**
 * Write a program to create a frame using Swing. Implement mouseClicked(), 
 * mouseEntered() and mouseExited() events. Frame should become visible 
 * when mouse enters it. 
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class Main {
    JLabel l;
    Main() {
        JFrame f = new JFrame("Swing Frame");
        l = new JLabel("", SwingConstants.CENTER);
        l.setBounds(15, 110, 260, 30);
        f.add(l);
        f.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                l.setText("Mouse Clicked");
            }
            @Override
            public void mouseEntered(MouseEvent e) {
                l.setText("Mouse Entered");
            }
            @Override
            public void mouseExited(MouseEvent e) {
                l.setText("Mouse Exited");
            }
        });
        f.setSize(300, 300);
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

