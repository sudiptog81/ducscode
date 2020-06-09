/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class CustomerRegistration extends JFrame {
    private JPanel mainPanel;
    private JTextField nameField;
    private JTextField addressField;
    private JTextField phoneField;
    private JButton addButton;
    private JButton resetButton;
    private JButton cancelButton;

    CustomerRegistration(Database db) {
        super("Add Customer");

        nameField.setText(null);
        phoneField.setText(null);
        addressField.setText(null);

        addButton.addActionListener(e -> {
            try {
                db.addCustomer(nameField.getText(), phoneField.getText(), addressField.getText());
                JOptionPane.showMessageDialog(
                        null, "Customer registration successful!",
                        "Customer Registered", JOptionPane.INFORMATION_MESSAGE
                );
                dispose();
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });
        resetButton.addActionListener(e -> {
            nameField.setText(null);
            phoneField.setText(null);
            addressField.setText(null);
        });
        cancelButton.addActionListener(e -> dispose());

        this.pack();
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                dispose();
            }
        });
        this.setSize(300, 200);
        this.setContentPane(mainPanel);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
}
