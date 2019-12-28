package pro.ghosh.sudipto.customerManagementSystem;

public class Customer {
    final int id;
    final String name;
    final String phone;
    final String address;

    Customer(int id, String name, String phone, String address) {
        this.id = id;
        this.name = name;
        this.phone = phone;
        this.address = address;
    }
}
