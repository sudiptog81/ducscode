package pro.ghosh.sudipto.shapeClass;

public class Square extends Shape {
    public Square(int edgeLength) {
        setEdges(4);
        setEdgeLength(edgeLength);
        setApothem();
    }

    @Override
    public double getArea() {
        return getEdgeLength() * getEdgeLength();
    }
}
