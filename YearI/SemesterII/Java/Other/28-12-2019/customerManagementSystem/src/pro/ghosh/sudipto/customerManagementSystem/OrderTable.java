/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class OrderTable extends JFrame {
    private JTable ordersTable;
    private JPanel mainPanel;
    private JScrollPane scrollPane;

    OrderTable(Database db) {
        super("Received Orders");

        try {
            ordersTable.setModel(new OrderTableModel(db.getOrders()));
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(
                    null, e.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE
            );
        }

        ordersTable.setFillsViewportHeight(true);
        scrollPane.setViewportView(ordersTable);

        this.pack();
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                dispose();
            }
        });
        this.setContentPane(mainPanel);
        this.setSize(1000, 400);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

}
