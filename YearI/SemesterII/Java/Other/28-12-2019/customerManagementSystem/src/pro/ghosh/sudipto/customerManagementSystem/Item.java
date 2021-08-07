/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

public class Item {
    final int id;
    final String name;
    final double price;
    final int stockQty;

    Item(int id, String name, double price, int stockQty) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.stockQty = stockQty;
    }
}
