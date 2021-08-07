/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;

public class ItemsTable extends JFrame {
    private JTable itemsTable;
    private JPanel mainPanel;
    private JScrollPane scrollPane;

    ItemsTable(Database db) {
        super("Items in Inventory");

        try {
            itemsTable.setModel(new ItemTableModel(db.getItems()));
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(
                    null, e.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE
            );
        }

        itemsTable.setFillsViewportHeight(true);
        scrollPane.setViewportView(itemsTable);

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
