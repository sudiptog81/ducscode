
/**** CGPA.java ****/
import java.awt.*;
import java.awt.event.*;

class CGPA extends Frame {
    Label l;
    Button btnClose;

    CGPA(String cgpa) {
        super("Previous Year CGPA");

        l = new Label("Your CGPA was: " + cgpa);
        l.setBounds(10, 50, 280, 30);
        l.setAlignment(Label.CENTER);

        btnClose = new Button("Close");
        btnClose.setBounds(20, 85, 260, 30);
        btnClose.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                dispose();
            }
        });

        this.add(l);
        this.add(btnClose);

        this.setSize(300, 150);
        this.setLayout(null);
        this.setVisible(true);
        this.setLocationRelativeTo(null);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }
}