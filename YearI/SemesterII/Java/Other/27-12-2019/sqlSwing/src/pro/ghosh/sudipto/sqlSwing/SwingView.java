package pro.ghosh.sudipto.sqlSwing;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class SwingView extends JFrame {
    JPanel swingPane;
    JLabel nameLabel;
    JButton addButton;
    JButton clearButton;
    JTextField nameField;
    JButton deleteButton;
    JLabel copyrightLabel;
    JButton refreshButton;
    JScrollPane studentPane;
    JList<String> studentList;

    /**
     * Queries all records in the table
     *
     * @param st SQL Statement Object
     * @return ListModel
     */
    ListModel<String> refresh(Statement st) {
        DefaultListModel<String> l = new DefaultListModel<String>();
        try {
            ResultSet r = st.executeQuery("select * from students");
            while (r.next()) {
                l.addElement(r.getString("name"));
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return l;
    }

    /**
     * Constructor for SwingView
     *
     * @param c  Connection Object
     * @param st Statement Object
     */
    SwingView(Connection c, Statement st) {
        super("SQL Swing");

        // Refresh at Init
        this.studentList.setModel(refresh(st));

        // refreshButton Listener
        refreshButton.addActionListener(e -> this.studentList.setModel(refresh(st)));

        // addButton Listener
        addButton.addActionListener(
                e -> {
                    try {
                        st.executeUpdate("insert into students (name) values ('" + nameField.getText() + "')");
                        JOptionPane.showMessageDialog(null, (new Student()).submit(this));
                        this.studentList.setModel(refresh(st));
                        this.nameField.setText(null);
                    } catch (SQLException ex) {
                        System.err.println(ex.getMessage());
                        JOptionPane.showMessageDialog(null, ex.getMessage());
                    }
                }
        );

        // deleteButton Listener
        deleteButton.addActionListener(
                e -> {
                    try {
                        st.executeUpdate("delete from students where id = " + (studentList.getSelectedIndex() + 1));
                        JOptionPane.showMessageDialog(null, (new Student()).delete(this));
                        this.studentList.setModel(refresh(st));
                    } catch (SQLException ex) {
                        System.err.println(ex.getMessage());
                        JOptionPane.showMessageDialog(null, ex.getMessage());
                    }
                }
        );

        // clearButton Listener
        clearButton.addActionListener(
                e -> {
                    try {
                        st.executeUpdate("delete from students");
                        JOptionPane.showMessageDialog(null, (new Student()).clear());
                        this.studentList.setModel(refresh(st));
                    } catch (SQLException ex) {
                        System.err.println(ex.getMessage());
                        JOptionPane.showMessageDialog(null, ex.getMessage());
                    }
                }
        );

        // Configure JFrame
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                try {
                    c.close();
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                } finally {
                    dispose();
                }
            }
        });
        this.pack();
        this.setContentPane(this.swingPane);
        this.setSize(600, 600);
        this.setVisible(true);
    }
}
