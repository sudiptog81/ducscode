package pro.ghosh.sudipto.bannerApplet;

import java.awt.*;
import java.applet.Applet;

/**
 * Write a program that creates a Banner and then creates a thread to scrolls the
 * message in the banner from right to left across the applet’s window.
 *
 * @author sudipto@ghosh.pro University of Delhi
 */
public class BannerApplet extends Applet implements Runnable {
    char character;
    Thread t = null;
    boolean stopFlag = true;
    String message = " THIS IS A BANNER MESSAGE ";

    @Override
    public void init() {
        super.init();
        this.setForeground(Color.red);
        this.setBackground(Color.yellow);
    }

    @Override
    public void start() {
        t = new Thread(this);
        stopFlag = false;
        t.start();
    }

    @Override
    public void run() {
        while (!stopFlag) {
            try {
                repaint();
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    @Override
    public void stop() {
        super.stop();
        stopFlag = true;
        t = null;
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        character = message.charAt(0);
        message = message.substring(1, message.length());
        message = message + character;
        g.drawString(message, 20, 30);
    }
}
