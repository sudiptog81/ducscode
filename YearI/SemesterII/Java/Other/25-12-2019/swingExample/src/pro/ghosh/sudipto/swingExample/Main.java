package pro.ghosh.sudipto.swingExample;

import javax.swing.*;
import java.awt.event.*;

public class Main extends JFrame {
    JTextField tf;
    JButton bt, cl;
    JLabel l0, l1, l2;

    Main() {
        super("Java Swing Example");

        tf = new JTextField();
        bt = new JButton("Submit");
        cl = new JButton("Close");
        l0 = new JLabel("WRITE SOMETHING & PRESS SUBMIT");
        l1 = new JLabel("Made by Sudipto Ghosh");
        l2 = new JLabel();

        tf.setBounds(50, 80, 185, 20);
        bt.setBounds(55, 110, 80, 30);
        cl.setBounds(150, 110, 80, 30);
        l0.setBounds(20, 40, 250, 30);
        l1.setBounds(70, 200, 150, 30);
        l2.setBounds(70, 155, 150, 30);

        l0.setHorizontalAlignment(JLabel.CENTER);
        l1.setHorizontalAlignment(JLabel.CENTER);
        l2.setHorizontalAlignment(JLabel.CENTER);

        cl.addActionListener(e -> dispose());
        bt.addActionListener(e -> l2.setText("You Entered: " + tf.getText()));

        this.add(bt);
        this.add(cl);
        this.add(tf);
        this.add(l0);
        this.add(l1);
        this.add(l2);
        this.setSize(305, 300);
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
