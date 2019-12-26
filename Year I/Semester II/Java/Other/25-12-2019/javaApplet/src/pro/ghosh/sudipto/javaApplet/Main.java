package pro.ghosh.sudipto.javaApplet;

import java.applet.Applet;
import java.awt.*;

public class Main extends Applet {
    int x, y, w, h;

    @Override
    public void init() {
        super.init();
        x = Integer.parseInt(getParameter("xVal"));
        y = Integer.parseInt(getParameter("yVal"));
        w = Integer.parseInt(getParameter("wVal"));
        h = Integer.parseInt(getParameter("hVal"));
        resize(300, 300);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        g.drawRect(x, y, w, h);
        g.drawString("Hello World", 100, 150);
    }
}
