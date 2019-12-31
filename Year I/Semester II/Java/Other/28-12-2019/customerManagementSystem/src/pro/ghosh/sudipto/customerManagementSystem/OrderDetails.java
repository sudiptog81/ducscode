/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class OrderDetails extends JFrame {
    private JButton deleteButton;
    private JButton markDeliveredButton;
    private JPanel mainPanel;
    private JTextField idField;
    private JTextField customerNameField;
    private JTextField customerPhoneField;
    private JTextField itemNameField;
    private JTextField billAmtField;
    private JTextField timestampField;
    private JTextField stateField;
    private JTextField itemQtyField;

    void refreshDetails(Database db, int id) {
        try {
            Order o = db.getOrder(id);
            Item i = db.getItem(o.item);
            Customer c = db.getCustomerById(o.customer);
            idField.setText("" + o.id);
            customerNameField.setText(c.name);
            customerPhoneField.setText("" + c.phone);
            itemNameField.setText(i.name);
            itemQtyField.setText("" + o.qty);
            billAmtField.setText("" + o.billAmt);
            timestampField.setText(o.timestamp);
            stateField.setText(o.state);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(
                    null, e.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE
            );
        }
    }

    OrderDetails(int id, Database db) {
        super("Order Details - " + id);

        refreshDetails(db, id);

        markDeliveredButton.addActionListener(e -> {
            try {
                db.updateOrder(id);
                JOptionPane.showMessageDialog(
                        null, "Order updated successfully!",
                        "Update Successful", JOptionPane.INFORMATION_MESSAGE
                );
                refreshDetails(db, id);
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });

        deleteButton.addActionListener(e -> {
            try {
                db.deleteOrder(id);
                JOptionPane.showMessageDialog(
                        null, "Order deletion successful!",
                        "Order " + id + " Deleted", JOptionPane.INFORMATION_MESSAGE
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
        this.setSize(350, 500);
        this.setContentPane(mainPanel);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

}
