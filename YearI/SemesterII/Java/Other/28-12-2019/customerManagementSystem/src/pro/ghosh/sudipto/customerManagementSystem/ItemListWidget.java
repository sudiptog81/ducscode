/*
 * @author Sudipto Ghosh, University of Delhi
 */

package pro.ghosh.sudipto.customerManagementSystem;

public final class ItemListWidget {
    private final int value;
    private final String key;

    public ItemListWidget(String key, int value) {
        this.value = value;
        this.key = key;
    }

    public int getValue() {
        return this.value;
    }

    @Override
    public String toString() {
        return this.key;
    }
}
