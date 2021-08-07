package pro.ghosh.sudipto.shapeClass;

abstract public class Shape {
    int edges;
    int edgeLength;
    double apothem;

    public void setApothem() {
        this.apothem = getEdgeLength() / (2 * Math.tan(Math.PI / getEdges()));
    }

    public void setEdges(int edges) {
        this.edges = edges;
    }

    public void setEdgeLength(int edgeLength) {
        this.edgeLength = edgeLength;
    }

    public int getEdges() {
        return edges;
    }

    public double getApothem() {
        return apothem;
    }

    public int getEdgeLength() {
        return edgeLength;
    }

    abstract double getArea();
}
