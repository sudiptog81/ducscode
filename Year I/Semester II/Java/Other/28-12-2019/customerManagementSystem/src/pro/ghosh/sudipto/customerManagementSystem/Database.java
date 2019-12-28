package pro.ghosh.sudipto.customerManagementSystem;

import java.sql.*;

public class Database {
    Connection c;
    Statement st;

    Database() throws SQLException {
        c = DriverManager.getConnection("jdbc:sqlite::memory:");
        st = c.createStatement();
        st.executeUpdate(
                "create table if not exists customers (customerId integer primary key autoincrement, "
                        + "customerName string, customerPhone string, customerAddress string)"
        );
        st.executeUpdate(
                "create table if not exists items (itemId integer primary key autoincrement, "
                        + "itemName string, itemPrice real, itemStock integer)"
        );
        st.executeUpdate(
                "create table if not exists orders (orderId integer primary key autoincrement, "
                        + "itemId integer, itemQty integer, customerId integer)"
        );
    }

    int checkCustomer(String phone) throws SQLException {
        ResultSet r = st.executeQuery("select * from customers where customerPhone  = " + phone);
        return r.getInt("customerId");
    }

    Customer getCustomer(String phone) throws SQLException {
        Customer c = null;
        ResultSet r = st.executeQuery("select * from customers where customerId = " + checkCustomer(phone));
        while (r.next()) {
            c = new Customer(
                    r.getInt("customerId"),
                    r.getString("customerName"),
                    r.getString("customerPhone"),
                    r.getString("customerAddress")
            );
        }
        return c;
    }

    Object[][] getCustomers() throws SQLException {
        int counter = 0;
        Object[][] c = new Object[countCustomers()][4];
        ResultSet r = st.executeQuery("select * from customers");
        while (r.next()) {
            c[counter] = new Object[4];
            c[counter][0] = r.getInt("customerId");
            c[counter][1] = r.getString("customerName");
            c[counter][2] = r.getString("customerPhone");
            c[counter][3] = r.getString("customerAddress");
            counter++;
        }
        return c;
    }

    void addCustomer(String name, String phone, String address) throws SQLException {
        if (name == null || name.equals("")) throw new SQLException("No Name provided");
        if (phone == null || phone.equals("")) throw new SQLException("No Phone Number provided");
        if (address == null || address.equals("")) throw new SQLException("No Address provided");
        st.executeUpdate(
                "insert into customers(customerName, customerPhone, customerAddress) "
                        + "values ('" + name + "', '" + phone + "', '" + address + "')"
        );
    }

    void updateCustomer(String phone, String name, String address) throws SQLException {
        if (name == null || name.equals("")) throw new SQLException("No Name provided");
        if (address == null || address.equals("")) throw new SQLException("No Address provided");
        st.executeUpdate(
                "update customers set customerName = '" + name
                        + "', customerAddress = '" + address
                        + "' where customerPhone = " + phone
        );
    }

    void deleteCustomer(String phone) throws SQLException {
        st.executeUpdate(
                "delete from customers where customerPhone = " + phone
        );
    }

    int countCustomers() throws SQLException {
        ResultSet r = st.executeQuery("select count(*) as count from customers");
        return r.getInt("count");
    }
}
