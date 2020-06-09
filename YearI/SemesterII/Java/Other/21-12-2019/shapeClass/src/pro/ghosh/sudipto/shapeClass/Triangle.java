package pro.ghosh.sudipto.shapeClass;

public class Triangle extends Shape {
    public Triangle(int edgeLength) {
        setEdges(3);
        setEdgeLength(edgeLength);
        setApothem();
    }

    @Override
    double getArea() {
        return (Math.sqrt(3) / 4) * (getEdgeLength() * getEdgeLength());
    }
}
