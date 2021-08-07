/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class CustomerTable extends JFrame {
    private JTable customersTable;
    private JPanel mainPanel;
    private JScrollPane scrollPane;

    CustomerTable(Database db) {
        super("Registered Customers");

        try {
            customersTable.setModel(new CustomerTableModel(db.getCustomers()));
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(
                    null, e.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE
            );
        }

        customersTable.setFillsViewportHeight(true);
        scrollPane.setViewportView(customersTable);

        this.pack();
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                dispose();
            }
        });
        this.setContentPane(mainPanel);
        this.setSize(400, 300);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

}
