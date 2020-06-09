
/**
 * Write a program to create a frame using AWT. Implement mouseClicked(), 
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

public class Main extends Frame implements MouseListener {
    final int length = 100;
    final int breadth = 100;

    Main() {
        super("AWT Frame");
        this.setSize(this.length, this.breadth);
        this.setLayout(null);
        this.setVisible(true);
        this.addMouseListener(this);
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
        this.setSize(this.length, this.breadth);
    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {
        this.setSize(3 * this.length, 3 * this.breadth);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        this.dispose();
    }
}