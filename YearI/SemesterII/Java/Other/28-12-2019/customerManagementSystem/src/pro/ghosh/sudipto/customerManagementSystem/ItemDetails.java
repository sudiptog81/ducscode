/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class ItemDetails extends JFrame {
    private JButton deleteButton;
    private JButton updateDetailsButton;
    private JPanel mainPanel;
    private JTextField idField;
    private JTextField nameField;
    private JTextField priceField;
    private JTextField qtyField;

    void refreshDetails(Database db, int id) {
        try {
            Item i = db.getItem(id);
            idField.setText("" + i.id);
            nameField.setText(i.name);
            priceField.setText("" + i.price);
            qtyField.setText("" + i.stockQty);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(
                    null, e.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE
            );
        }
    }

    ItemDetails(int id, Database db) {
        super("Item Details - " + id);

        refreshDetails(db, id);

        updateDetailsButton.addActionListener(e -> {
            try {
                db.updateItem(id, Double.parseDouble(priceField.getText()), Integer.parseInt(qtyField.getText()));
                JOptionPane.showMessageDialog(
                        null, "Item updated successfully!",
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
                db.deleteItem(id);
                JOptionPane.showMessageDialog(
                        null, "Item deletion successful!",
                        "Item " + id + " Deleted", JOptionPane.INFORMATION_MESSAGE
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
