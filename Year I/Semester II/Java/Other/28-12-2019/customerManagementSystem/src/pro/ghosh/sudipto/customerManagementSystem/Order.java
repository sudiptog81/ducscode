/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

public class Order {
    final int id;
    final int customer;
    final int item;
    final int qty;
    final double billAmt;
    final String timestamp;
    final String state;

    Order(int id, int customerId, int itemId, int qty, double billAmt, String timestamp, String state) {
        this.id = id;
        this.customer = customerId;
        this.item = itemId;
        this.qty = qty;
        this.billAmt = billAmt;
        this.timestamp = timestamp;
        this.state = state;
    }
}
