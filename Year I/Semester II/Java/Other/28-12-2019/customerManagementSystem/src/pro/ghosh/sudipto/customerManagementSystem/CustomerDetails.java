package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class CustomerDetails extends JFrame {
    private JButton addOrderButton;
    private JButton deleteButton;
    private JButton updateDetailsButton;
    private JPanel mainPanel;
    private JTextField idField;
    private JTextField nameField;
    private JTextField phoneField;
    private JTextField addressField;

    void refreshDetails(Database db, String phone) {
        try {
            Customer c = db.getCustomer(phone);
            idField.setText("" + c.id);
            nameField.setText(c.name);
            phoneField.setText(c.phone);
            addressField.setText(c.address);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(
                    null, e.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE
            );
        }
    }

    CustomerDetails(String phone, Database db) {
        super("Customer Details - " + phone);

        refreshDetails(db, phone);

        updateDetailsButton.addActionListener(e -> {
            try {
                db.updateCustomer(phone, nameField.getText(), addressField.getText());
                JOptionPane.showMessageDialog(
                        null, "Details updated successfully!",
                        "Update Successful", JOptionPane.INFORMATION_MESSAGE
                );
                refreshDetails(db, phone);
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });

        deleteButton.addActionListener(e -> {
            try {
                db.deleteCustomer(phone);
                JOptionPane.showMessageDialog(
                        null, "Customer deletion successful!",
                        "Customer " + phone + " Deleted", JOptionPane.INFORMATION_MESSAGE
                );
                dispose();
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });

        this.pack();
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                dispose();
            }
        });
        this.setSize(350, 225);
        this.setContentPane(mainPanel);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
}
