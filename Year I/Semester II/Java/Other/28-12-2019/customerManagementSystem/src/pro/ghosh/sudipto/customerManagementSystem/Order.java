package pro.ghosh.sudipto.customerManagementSystem;

public class Order {
    int id;
    int customer;
    int item;
    int qty;
    double billAmt;

    Order(int id, int customerId, int itemId, int qty, double billAmt) {
        this.id = id;
        this.customer = customerId;
        this.item = itemId;
        this.qty = qty;
        this.billAmt = billAmt;
    }
}
