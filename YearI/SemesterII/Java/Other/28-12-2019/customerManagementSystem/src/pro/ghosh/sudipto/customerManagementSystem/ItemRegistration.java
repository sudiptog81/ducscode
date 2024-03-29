/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class ItemRegistration extends JFrame {
    private JPanel mainPanel;
    private JTextField nameField;
    private JSpinner qtyField;
    private JTextField priceField;
    private JButton addButton;
    private JButton resetButton;
    private JButton cancelButton;

    ItemRegistration(Database db) {
        super("Add New Item");

        qtyField.setModel(new SpinnerNumberModel(0, 0, 1000, 1));

        nameField.setText(null);
        priceField.setText("0.00");
        qtyField.setValue(0);

        addButton.addActionListener(e -> {
            try {
                db.addItem(
                        nameField.getText(),
                        Double.parseDouble(
                                priceField.getText().isEmpty() ?
                                        "0.00" : priceField.getText()
                        ),
                        Integer.parseInt(
                                qtyField.getValue().toString().isEmpty() ?
                                        "-1" : qtyField.getValue().toString()
                        )
                );
                JOptionPane.showMessageDialog(
                        null, "Item successfully added to inventory!",
                        "Item Added", JOptionPane.INFORMATION_MESSAGE
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
            priceField.setText("0.00");
            qtyField.setValue(0);
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
