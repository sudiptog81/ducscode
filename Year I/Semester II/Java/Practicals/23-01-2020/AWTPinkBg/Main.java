
/**
 * Using AWT, write a program to display a string in frame 
 * window with pink colour as background.
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/
import java.awt.*;
import java.awt.event.*;

public class Main extends Frame {
    Label l;

    Main() {
        super("AWT Pink");
        l = new Label("This is a Label");
        l.setBounds(25, 50, 250, 30);
        l.setAlignment(Label.CENTER);
        this.add(l);
        this.setBackground(Color.PINK);
        this.setSize(300, 100);
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
}