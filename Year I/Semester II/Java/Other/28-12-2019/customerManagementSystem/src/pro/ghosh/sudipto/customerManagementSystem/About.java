package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;

public class About extends JFrame {
    private JPanel mainPanel;
    private JButton closeDialogButton;
    private JTextPane aboutTextPane;

    About() {
        super("About this CMS");

        closeDialogButton.addActionListener(e -> dispose());

        this.pack();
        this.setSize(300, 250);
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
}
