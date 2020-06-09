package pro.ghosh.sudipto.awtExample;

import java.awt.*;
import java.awt.event.*;

public class Main extends Frame {
    TextField tf;
    Button bt, cl;
    Label l0, l1, l2;

    Main() {
        super("Java AWT Example");

        tf = new TextField();
        cl = new Button("Close");
        bt = new Button("Submit");
        l0 = new Label("WRITE SOMETHING & PRESS SUBMIT");
        l1 = new Label("Made by Sudipto Ghosh");
        l2 = new Label();

        tf.setBounds(60, 110, 180, 20);
        bt.setBounds(75, 145, 60, 30);
        cl.setBounds(165, 145, 60, 30);
        l0.setBounds(25, 60, 250, 30);
        l1.setBounds(75, 250, 150, 30);
        l2.setBounds(75, 190, 150, 30);

        l0.setAlignment(Label.CENTER);
        l1.setAlignment(Label.CENTER);
        l2.setAlignment(Label.CENTER);

        l0.setFont(new Font("Sans Serif", Font.BOLD, 12));

        cl.addActionListener(e -> dispose());
        bt.addActionListener(e -> l2.setText("You Entered: " + tf.getText()));

        this.add(bt);
        this.add(cl);
        this.add(tf);
        this.add(l0);
        this.add(l1);
        this.add(l2);
        this.setSize(300, 300);
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
