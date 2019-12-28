package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class Main extends JFrame {

    private JPanel mainPanel;
    private JLabel logoLabel;
    private JButton findCustomerButton;
    private JButton addCustomerButton;
    private JLabel customersLabel;
    private JButton viewCustomersButton;
    private JButton aboutHRSButton;
    private JPanel logoPanel;

    Database db;

    void refreshCounter() throws SQLException {
        customersLabel.setText("Registered Customers: " + db.countCustomers());
    }

    Main() {
        super("Customer Management System");

        try {
            db = new Database("jdbc:sqlite::memory:");
            refreshCounter();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(
                    null, e.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE
            );
            System.err.println(e.getMessage());
        }

        logoLabel.setIcon(new ImageIcon(Toolkit.getDefaultToolkit().getImage("resources/logo.png")));

        findCustomerButton.addActionListener(e -> {
            String phone = JOptionPane.showInputDialog(
                    null, "Enter Phone Number",
                    "Find Customer", JOptionPane.QUESTION_MESSAGE
            );
            if (phone == null)
                JOptionPane.showMessageDialog(
                        null, "Enter a valid phone number",
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            else if (!phone.isEmpty())
                try {
                    if (db.checkCustomer(phone) != -1) new CustomerDetails(phone, db);
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(
                            null, ex.getMessage(),
                            "Error", JOptionPane.ERROR_MESSAGE
                    );
                }
        });

        addCustomerButton.addActionListener(e -> {
            new CustomerRegistration(db);
        });

        viewCustomersButton.addActionListener(e -> {
            try {
                if (db.countCustomers() > 0) new CustomerTable(db);
                else JOptionPane.showMessageDialog(
                        null, "No registered customers exist!",
                        "Empty Database", JOptionPane.ERROR_MESSAGE
                );
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });

        aboutHRSButton.addActionListener(e -> {
            new About();
        });

        this.pack();
        this.setContentPane(mainPanel);
        this.setSize(350, 350);
        this.addWindowFocusListener(new WindowAdapter() {
            @Override
            public void windowGainedFocus(WindowEvent e) {
                super.windowGainedFocus(e);
                try {
                    refreshCounter();
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(
                            null, ex.getMessage(),
                            "Error", JOptionPane.ERROR_MESSAGE
                    );
                }
            }
        });
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                dispose();
            }
        });
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    public static void main(String[] args) {
        new Main();
    }
}
