
/**** CGPA.java ****/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class CGPA {
    JLabel l;
    JButton btnClose;

    CGPA(String cgpa) {
        JFrame f = new JFrame("Previous Year CGPA");
        l = new JLabel("Your CGPA was: " + cgpa, SwingConstants.CENTER);
        l.setBounds(20, 20, 250, 30);
        btnClose = new JButton("Close");
        btnClose.setBounds(90, 60, 100, 30);
        btnClose.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                f.dispose();
            }
        });
        f.add(l);
        f.add(btnClose);
        f.setSize(310, 150);
        f.setLayout(null);
        f.setVisible(true);
        f.setLocationRelativeTo(null);
        f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    }
}