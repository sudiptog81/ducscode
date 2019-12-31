/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

import java.sql.*;

public class Database {
    Connection c;
    Statement st;

    Database() throws SQLException {
        c = DriverManager.getConnection("jdbc:sqlite::memory:");
        st = c.createStatement();
        init();
    }

    void init() throws SQLException {
        st.executeUpdate(
                "create table if not exists customers (customerId integer primary key autoincrement, "
                        + "customerName string, customerPhone string unique, customerAddress string)"
        );
        st.executeUpdate(
                "create table if not exists items (itemId integer primary key autoincrement, "
                        + "itemName string, itemPrice real, itemStock integer)"
        );
        st.executeUpdate(
                "create table if not exists orders (orderId integer primary key autoincrement, "
                        + "itemId integer, itemQty integer, customerId integer, billAmt real, state string "
                        + "default 'PROCESSING', "
                        + "ordered_at DATETIME NOT NULL DEFAULT (strftime('%Y-%m-%d %H:%M:%S', 'now', 'localtime')))"
        );
    }

    void flush() throws SQLException {
        st.executeUpdate("drop table if exists customers");
        st.executeUpdate("drop table if exists items");
        st.executeUpdate("drop table if exists orders");
    }

    int checkCustomer(String phone) throws SQLException {
        ResultSet r = st.executeQuery("select * from customers where customerPhone  = " + phone);
        return r.getInt("customerId") > 0 ? r.getInt("customerId") : -1;
    }

    int checkItem(int id) throws SQLException {
        ResultSet r = st.executeQuery("select * from items where itemId = " + id);
        return r.getInt("itemId") > 0 ? r.getInt("itemId") : -1;
    }

    int checkOrder(int id) throws SQLException {
        ResultSet r = st.executeQuery("select * from orders where orderId = " + id);
        return r.getInt("orderId") > 0 ? r.getInt("orderId") : -1;
    }

    Customer getCustomer(String phone) throws SQLException {
        if (checkCustomer(phone) == -1) throw new SQLException("Customer not found!");
        ResultSet r = st.executeQuery("select * from customers where customerId = " + checkCustomer(phone));
        return new Customer(
                r.getInt("customerId"),
                r.getString("customerName"),
                r.getString("customerPhone"),
                r.getString("customerAddress")
        );
    }

    Customer getCustomerById(int id) throws SQLException {
        ResultSet r = st.executeQuery("select * from customers where customerId = " + id);
        return new Customer(
                r.getInt("customerId"),
                r.getString("customerName"),
                r.getString("customerPhone"),
                r.getString("customerAddress")
        );
    }

    Item getItem(int id) throws SQLException {
        if (checkItem(id) == -1) throw new SQLException("Item not found!");
        ResultSet r = st.executeQuery("select * from items where itemId = " + id);
        return new Item(
                r.getInt("itemId"),
                r.getString("itemName"),
                r.getDouble("itemPrice"),
                r.getInt("itemStock")
        );
    }

    Order getOrder(int id) throws SQLException {
        if (checkOrder(id) == -1) throw new SQLException("Item not found!");
        ResultSet r = st.executeQuery(
                "select * from orders where orderId = " + id
        );
        return new Order(
                r.getInt("orderId"),
                r.getInt("customerId"),
                r.getInt("itemId"),
                r.getInt("itemQty"),
                r.getDouble("billAmt"),
                r.getString("ordered_at"),
                r.getString("state")
        );
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

    Object[][] getItems() throws SQLException {
        int counter = 0;
        Object[][] i = new Object[countItems()][4];
        ResultSet r = st.executeQuery("select * from items");
        while (r.next()) {
            i[counter] = new Object[4];
            i[counter][0] = r.getInt("itemId");
            i[counter][1] = r.getString("itemName");
            i[counter][2] = r.getDouble("itemPrice");
            i[counter][3] = r.getInt("itemStock");
            counter++;
        }
        return i;
    }

    Object[][] getOrders() throws SQLException {
        int counter = 0;
        Object[][] o = new Object[countOrders()][8];
        ResultSet r = st.executeQuery(
                "select orders.orderId, customers.customerName, customers.customerPhone, "
                        + "items.itemName, orders.itemQty, orders.billAmt, orders.ordered_at, orders.state from orders "
                        + "inner join customers on orders.customerId = customers.customerId "
                        + "inner join items on orders.itemId = items.itemId"
        );
        while (r.next()) {
            o[counter] = new Object[8];
            o[counter][0] = r.getInt("orderId");
            o[counter][1] = r.getString("customerName");
            o[counter][2] = r.getString("customerPhone");
            o[counter][3] = r.getString("itemName");
            o[counter][4] = r.getInt("itemQty");
            o[counter][5] = r.getDouble("billAmt");
            o[counter][6] = r.getString("ordered_at");
            o[counter][7] = r.getString("state");
            counter++;
        }
        return o;
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

    void addItem(String name, double price, int quantity) throws SQLException {
        if (name == null || name.equals("")) throw new SQLException("No Item Name provided");
        if (price <= 0) throw new SQLException("Invalid price");
        if (quantity < 0) throw new SQLException("Invalid quantity");
        st.executeUpdate(
                "insert into items (itemName, itemPrice, itemStock) "
                        + "values ('" + name + "', " + price + ", " + quantity + ")"
        );
    }

    void addOrder(int customerId, int itemId, int quantity) throws SQLException {
        if (itemId <= 0) throw new SQLException("Invalid Item ID");
        if (quantity <= 0) throw new SQLException("Invalid Quantity");
        if (customerId <= 0) throw new SQLException("Invalid Customer ID");
        if (
                getItem(itemId).stockQty <= 0 ||
                        getItem(itemId).stockQty - quantity <= 0
        )
            throw new SQLException("Item Out of Stock");
        st.executeUpdate(
                "update items set itemStock = itemStock - " + quantity
                        + " where itemId = " + itemId
        );
        st.executeUpdate(
                "insert into orders (itemId, itemQty, customerId, billAmt) values "
                        + "(" + itemId + ", " + quantity + ", " + customerId + ", "
                        + getItem(itemId).price * quantity + ")"
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

    void updateItem(int id, double price, int qty) throws SQLException {
        if (qty < 0) throw new SQLException("Invalid quantity");
        if (price <= 0) throw new SQLException("Invalid price");
        st.executeUpdate(
                "update items set itemStock = " + qty
                        + ", itemPrice = " + price
                        + " where itemId = " + id
        );
    }

    void updateOrder(int id) throws SQLException {
        st.executeUpdate("update orders set state = 'DELIVERED' where orderId = " + id);
    }

    void deleteCustomer(String phone) throws SQLException {
        st.executeUpdate(
                "delete from customers where customerPhone = " + phone
        );
    }

    void deleteItem(int id) throws SQLException {
        st.executeUpdate(
                "delete from items where itemId = " + id
        );
    }

    void deleteOrder(int id) throws SQLException {
        st.executeUpdate(
                "delete from orders where orderId = " + id
        );
    }

    int countCustomers() throws SQLException {
        ResultSet r = st.executeQuery("select count(*) as count from customers");
        return r.getInt("count");
    }

    int countItems() throws SQLException {
        ResultSet r = st.executeQuery("select count(*) as count from items");
        return r.getInt("count");
    }

    int countOrders() throws SQLException {
        ResultSet r = st.executeQuery("select count(*) as count from orders");
        return r.getInt("count");
    }

    int countOpenOrders() throws SQLException {
        ResultSet r = st.executeQuery("select count(*) as count from orders where state = 'PROCESSING'");
        return r.getInt("count");
    }

    void close() throws SQLException {
        c.close();
    }
}
