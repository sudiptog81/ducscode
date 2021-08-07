
/**
 * Using Swing, write a program to create two buttons labelled
 * 'A' and 'B'. When button 'A' is pressed, it displays your
 * personal information (Name, Course, Roll No, College) and
 * when button 'B' is pressed, it displays your CGPA in
 * previous semester.
 *
 * @author sudipto@ghosh.pro University of Delhi
 */

/**** Main.java ****/

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class Main implements ActionListener {
	public static void main(String[] args) {
		SwingUtilities.invokeLater(Main::new);
	}

	JButton btnInfo, btnCGPA;

	Main() {
		JFrame f = new JFrame("Student Details");
		this.btnInfo = new JButton("A");
		this.btnInfo.setBounds(18, 100, 450, 100);
		this.btnInfo.addActionListener(this);
		f.add(this.btnInfo);
		this.btnCGPA = new JButton("B");
		this.btnCGPA.setBounds(18, 270, 450, 100);
		this.btnCGPA.addActionListener(this);
		f.add(this.btnCGPA);
		f.setSize(500, 500);
		f.setLayout(null);
		f.setVisible(true);
		f.setLocationRelativeTo(null);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == this.btnInfo) {
			new Information("SUDIPTO GHOSH", "BSc (Hons) Computer Science", "19/78003", "ARSD College");
		} else if (e.getSource() == this.btnCGPA) {
			new CGPA("9.73");
		}
	}
}
