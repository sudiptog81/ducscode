package pro.ghosh.sudipto.notepadClone;

import javax.swing.*;
import java.awt.event.*;

public class About extends JFrame {
    private JPanel aboutPanel;
    private JLabel aboutLabel;

    About() {
        super("About this Notepad Clone");

        this.aboutLabel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent e) {
                dispose();
            }
        });

        this.pack();
        this.setContentPane(this.aboutPanel);
        this.setSize(500, 100);
        this.setLocationRelativeTo(null);
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                dispose();
            }
        });
        this.setVisible(true);
    }
}
