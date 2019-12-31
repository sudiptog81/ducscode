/*
 * @author Sudipto Ghosh, University of Delhi
 */

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
    private JButton aboutCMSButton;
    private JButton addNewItemButton;
    private JButton updateItemButton;
    private JButton viewInventoryButton;
    private JLabel itemsLabel;
    private JButton viewOrdersButton;
    private JButton findOrderButton;
    private JButton flushDatabaseButton;
    private JLabel openOrdersLabel;
    private JLabel ordersLabel;
    private JPanel logoPanel;

    Database db;

    void refreshCounter() throws SQLException {
        ordersLabel.setText("Orders Received: " + db.countOrders());
        openOrdersLabel.setText("Open Orders: " + db.countOpenOrders());
        itemsLabel.setText("Items in Inventory: " + db.countItems());
        customersLabel.setText("Registered Customers: " + db.countCustomers());
    }

    Main() {
        super("Customer Management System");

        try {
            db = new Database();
            refreshCounter();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(
                    null, e.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE
            );
            System.err.println(e.getMessage());
        }

        logoLabel.setIcon(new ImageIcon(Toolkit.getDefaultToolkit().getImage(
                getClass().getClassLoader().getResource("img/logo.png")
        )));

        findOrderButton.addActionListener(e -> {
            String idBuffer = JOptionPane.showInputDialog(
                    null, "Enter Order Number",
                    "Find Order", JOptionPane.QUESTION_MESSAGE
            );

            if (idBuffer.isEmpty())
                JOptionPane.showMessageDialog(
                        null, "Enter a valid Order ID",
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            else try {
                int id = Integer.parseInt(idBuffer);
                if (db.checkOrder(id) != -1) new OrderDetails(id, db);
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });

        viewOrdersButton.addActionListener(e -> {
            try {
                if (db.countOrders() > 0) new OrderTable(db);
                else JOptionPane.showMessageDialog(
                        null, "No orders received!",
                        "Empty Database", JOptionPane.ERROR_MESSAGE
                );
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });

        findCustomerButton.addActionListener(e -> {
            String phone = JOptionPane.showInputDialog(
                    null, "Enter Phone Number",
                    "Find Customer", JOptionPane.QUESTION_MESSAGE
            );
            if (phone == null || phone.isEmpty())
                JOptionPane.showMessageDialog(
                        null, "Enter a valid phone number",
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            else try {
                if (db.checkCustomer(phone) != -1) new CustomerDetails(phone, db);
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });


        addCustomerButton.addActionListener(e -> new CustomerRegistration(db));

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

        addNewItemButton.addActionListener(e -> new ItemRegistration(db));

        updateItemButton.addActionListener(e -> {
            String idBuffer = JOptionPane.showInputDialog(
                    null, "Enter Item ID",
                    "Find Item by ID", JOptionPane.QUESTION_MESSAGE
            );
            int id = idBuffer.isEmpty() ? -1 : Integer.parseInt(idBuffer);
            if (id <= 0)
                JOptionPane.showMessageDialog(
                        null, "Enter a valid Item ID",
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            else try {
                if (db.checkItem(id) != -1) new ItemDetails(id, db);
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });

        viewInventoryButton.addActionListener(e -> {
            try {
                if (db.countItems() > 0) new ItemsTable(db);
                else JOptionPane.showMessageDialog(
                        null, "No items exist in inventory!",
                        "Empty Database", JOptionPane.ERROR_MESSAGE
                );
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });

        aboutCMSButton.addActionListener(e -> new About());

        flushDatabaseButton.addActionListener(e -> {
            try {
                db.flush();
                db.init();
                JOptionPane.showMessageDialog(
                        null, "Database cleared successfully!",
                        "Database Flushed", JOptionPane.INFORMATION_MESSAGE
                );
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(
                        null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        });

        this.pack();
        this.setContentPane(mainPanel);
        this.setSize(400, 420);
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
                try {
                    db.close();
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(
                            null, ex.getMessage(),
                            "Error", JOptionPane.ERROR_MESSAGE
                    );
                }
            }
        });
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    public static void main(String[] args) {
        new Main();
    }

}
