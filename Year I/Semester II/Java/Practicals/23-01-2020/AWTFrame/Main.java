
/**
 * Write a program to create a frame using AWT. Implement mouseClicked(), 
 * mouseEntered() and mouseExited() events. Frame should become visible 
 * when mouse enters it. 
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/
import java.awt.*;
import java.awt.event.*;

public class Main extends Frame implements MouseListener {
    Label l;

    Main() {
        super("AWT Frame");

        l = new Label();

        l.setBounds(25, 60, 250, 30);
        l.setAlignment(Label.CENTER);
        this.add(l);

        this.setSize(300, 300);
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
        l.setText("Mouse Clicked");
    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {
        l.setText("Mouse Entered");
    }

    @Override
    public void mouseExited(MouseEvent e) {
        l.setText("Mouse Exited");
    }
}