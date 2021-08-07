class Distance {
    int feet;
    int inches;

    Distance(int feet, int inches) {
	this.feet = feet;
	this.inches = inches;
	this.normalize();
    }

    Distance(Distance o) {
	this.feet = o.feet;
	this.inches = o.inches;
    }

    void normalize() {
	this.feet += this.inches / 12;
	this.inches %= 12;
    }

    void display() {
	System.out.println("Distance: " + this.feet + "\'" + this.inches + "\"");
    }
}