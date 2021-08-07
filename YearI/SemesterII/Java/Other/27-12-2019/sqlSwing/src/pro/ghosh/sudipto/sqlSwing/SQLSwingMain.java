package pro.ghosh.sudipto.sqlSwing;

import javax.swing.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class SQLSwingMain {
    public static void main(String[] args) {
        Statement st;
        Connection c = null;
        try {
            c = DriverManager.getConnection("jdbc:sqlite::memory:");
            st = c.createStatement();
            st.setQueryTimeout(30);
            st.executeUpdate(
                    "create table if not exists students (id integer primary key autoincrement, name string)"
            );
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
            new SwingView(c, st);
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
}
