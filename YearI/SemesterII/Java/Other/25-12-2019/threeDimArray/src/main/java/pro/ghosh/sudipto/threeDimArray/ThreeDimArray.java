package pro.ghosh.sudipto.threeDimArray;

/**
 * ThreeDimArray
 */
public class ThreeDimArray {
    int a;
    int b;
    int c;
    int[][][] array;

    /**
     * Constuctor
     * 
     * @param a dimension 1
     * @param b dimension 2
     * @param c dimension 3
     */
    public ThreeDimArray(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.array = new int[this.a][this.b][this.c];
        for (int i = 0; i < this.a; i++) {
            for (int j = 0; j < this.b; j++) {
                for (int k = 0; k < this.c; k++) {
                    this.array[i][j][k] = 0;
                }
            }
        }
    }

    /**
     * Populate the array
     */
    public void populate() {
        for (int i = 0; i < this.a; i++) {
            for (int j = 0; j < this.b; j++) {
                for (int k = 0; k < this.c; k++) {
                    this.array[i][j][k] = i * j * k;
                }
            }
        }
    }

    /**
     * Print array to console
     */
    public void print() {
        for (int i = 0; i < this.a; i++) {
            for (int j = 0; j < this.b; j++) {
                for (int k = 0; k < this.c; k++) {
                    System.out.print(this.array[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}