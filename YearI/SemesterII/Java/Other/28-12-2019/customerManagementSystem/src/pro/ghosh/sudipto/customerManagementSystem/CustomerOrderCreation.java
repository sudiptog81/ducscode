/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class CustomerOrderCreation extends JFrame {

    private JPanel mainPanel;
    private JComboBox<ItemListWidget> itemField;
    private JSpinner qtyField;
    private JTextField amtField;
    private JButton cancelButton;
    private JButton confirmButton;

    private int quantity;
    private int selectedItem;
    private Object[][] items;

    CustomerOrderCreation(Database db, int customerId) {
        super("Create New Order");

        qtyField.setModel(new SpinnerNumberModel(0, 0, 100, 1));

        try {
            populateItems(db);
            refreshAmount();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(
                    null, e.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE
            );
        }

        itemField.addActionListener(e -> refreshAmount());

        qtyField.addChangeListener(e -> refreshAmount());

        cancelButton.addActionListener(e -> dispose());

        confirmButton.addActionListener(e -> {
            try {
                db.addOrder(customerId, this.selectedItem + 1, this.quantity);
                JOptionPane.showMessageDialog(
                        null, "Order created successfully!",
                        "Update Successful", JOptionPane.INFORMATION_MESSAGE
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
        this.setSize(400, 175);
        this.setContentPane(mainPanel);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    void refreshAmount() {
        String qtyBuffer = qtyField.getValue().toString();
        this.quantity = qtyBuffer.isEmpty() ? 0 : Integer.parseInt(qtyBuffer);
        this.selectedItem = itemField.getSelectedIndex();
        amtField.setText(
                "" + (double) this.items[this.selectedItem][2] * this.quantity
        );
    }

    void populateItems(Database db) throws SQLException {
        this.items = db.getItems();
        for (Object[] arr : this.items)
            itemField.addItem(
                    new ItemListWidget(arr[0] + " - " + arr[1], (int) arr[0])
            );
    }
}
