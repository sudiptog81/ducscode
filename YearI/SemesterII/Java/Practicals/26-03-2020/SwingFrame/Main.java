
/**
 * Write a program to create a frame using Swing. Implement mouseClicked(), 
 * mouseEntered() and mouseExited() events such that:
 *  - Size of the frame should be tripled when mouse enters it
 *  - Frame should reduce to its original size when mouse is clicked in it
 *  - Close the frame when mouse exits it
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Main {
    final int length = 100;
    final int breadth = 100;

    Main() {
        JFrame f = new JFrame("Swing Frame");
        f.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                f.setSize(3 * length, 3 * breadth);
            }

            @Override
            public void mouseClicked(MouseEvent e) {
                f.setSize(length, breadth);
            }

            @Override
            public void mouseExited(MouseEvent e) {
                f.dispose();
            }
        });
        f.setSize(this.length, this.breadth);
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
