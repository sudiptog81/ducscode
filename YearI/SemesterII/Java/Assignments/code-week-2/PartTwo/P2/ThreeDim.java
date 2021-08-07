package P2;

import P1.*;

public class ThreeDim extends TwoDim {
    private int z;

    public ThreeDim() {
        super(0, 0);
        this.z = 0;
    }

    public ThreeDim(int x, int y, int z) {
        super(x, y);
        this.z = z;
    }

    @Override
    public String toString() {
        return super.toString() + " z = " + z;
    }
}