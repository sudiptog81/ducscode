package pro.ghosh.sudipto.genericApplet;

import javax.swing.*;
import java.applet.Applet;
import java.awt.*;

public class Main extends Applet {
    private JPanel mainPanel;
    private JTextField nameField;
    private JButton nameButton;
    private JButton closeAppletButton;
    private String name;

    @Override
    public void init() {
        super.init();
        this.add(mainPanel);
        this.repaint();
        nameButton.addActionListener(e -> {
            this.name = JOptionPane.showInputDialog(
                    null, "Enter your name",
                    "Name Input", JOptionPane.INFORMATION_MESSAGE
            );
            nameField.setText(this.name);
            this.repaint();
        });
        closeAppletButton.addActionListener(e -> this.destroy());
    }

    @Override
    public void start() {
        super.start();
    }

    @Override
    public void stop() {
        super.stop();
    }

    @Override
    public void destroy() {
        super.destroy();
        System.exit(0);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
    }
}
