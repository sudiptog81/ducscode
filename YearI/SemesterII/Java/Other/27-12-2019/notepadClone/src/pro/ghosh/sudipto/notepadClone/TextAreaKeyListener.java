package pro.ghosh.sudipto.notepadClone;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class TextAreaKeyListener extends KeyAdapter {
    Main m;

    TextAreaKeyListener(Main m) {
        this.m = m;
    }

    @Override
    public void keyReleased(KeyEvent e) {
        this.m.refreshCounters();
    }
}
