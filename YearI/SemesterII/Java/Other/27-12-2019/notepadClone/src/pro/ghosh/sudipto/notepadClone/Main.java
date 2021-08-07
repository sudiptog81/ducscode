package pro.ghosh.sudipto.notepadClone;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.StringTokenizer;

/**
 * Notepad Clone - Java Edition
 *
 * @author sudipto@ghosh.pro University of Delhi
 */
public class Main extends JFrame {
    JPanel mainPanel;
    JLabel wordsLabel;
    JLabel charactersLabel;
    JMenuBar menuBar;
    JTextArea textArea;
    JMenu fileMenu;
    JMenu helpMenu;
    JMenuItem openMenuItem;
    JMenuItem saveMenuItem;
    JMenuItem aboutMenuItem;
    JMenuItem closeMenuItem;
    MenuListener menuListener;
    TextAreaKeyListener textAreaKeyListener;

    Main() {
        super("Notepad Clone - Java Edition");

        this.menuListener = new MenuListener(this);
        this.fileMenu = new JMenu("File");
        this.helpMenu = new JMenu("Help");
        this.openMenuItem = new JMenuItem("Open");
        this.saveMenuItem = new JMenuItem("Save");
        this.closeMenuItem = new JMenuItem("Close");
        this.aboutMenuItem = new JMenuItem("About");
        this.openMenuItem.addActionListener(this.menuListener);
        this.saveMenuItem.addActionListener(this.menuListener);
        this.closeMenuItem.addActionListener(this.menuListener);
        this.aboutMenuItem.addActionListener(this.menuListener);
        this.fileMenu.add(this.openMenuItem);
        this.fileMenu.add(this.saveMenuItem);
        this.fileMenu.add(this.closeMenuItem);
        this.helpMenu.add(this.aboutMenuItem);
        this.menuBar.add(this.fileMenu);
        this.menuBar.add(this.helpMenu);

        this.textArea.setText(null);
        this.textAreaKeyListener = new TextAreaKeyListener(this);
        this.textArea.addKeyListener(this.textAreaKeyListener);

        this.refreshCounters();

        this.setJMenuBar(this.menuBar);
        this.setContentPane(this.mainPanel);
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                dispose();
            }
        });
        this.pack();
        this.setSize(600, 600);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    public void refreshCounters() {
        String text = this.textArea.getText();
        StringTokenizer tokens = new StringTokenizer(text);
        this.wordsLabel.setText("" + tokens.countTokens());
        this.charactersLabel.setText("" + text.length());
    }

    public static void main(String[] args) {
        new Main();
    }
}
