
/**
 * Using Swing, write a program to create two buttons named "Red"
 * and "Blue". When a button is pressed the background colour should
 * be set to the colour named by the button’s label.
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/

import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class Main {
	public static void main(String[] args) {
		SwingUtilities.invokeLater(Main::new);
	}

	JButton btnRed, btnBlue;

	Main() {
		JFrame f = new JFrame("Swing Buttons");
		this.btnRed = new JButton("Red");
		this.btnRed.setBounds(16, 20, 250, 30);
		this.btnRed.addActionListener(e -> f.getContentPane().setBackground(Color.RED));
		f.add(this.btnRed);
		this.btnBlue = new JButton("Blue");
		this.btnBlue.setBounds(16, 65, 250, 30);
		this.btnBlue.addActionListener(e -> f.getContentPane().setBackground(Color.BLUE));
		f.add(this.btnBlue);
		f.setSize(300, 160);
		f.setLayout(null);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
