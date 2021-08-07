
/**** CGPA.java ****/

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

class CGPA {
	JLabel l;
	JButton btnClose;

	CGPA(String cgpa) {
		JFrame f = new JFrame("Previous Year CGPA");
		this.l = new JLabel("Your CGPA was: " + cgpa, SwingConstants.CENTER);
		this.l.setBounds(20, 20, 250, 30);
		this.btnClose = new JButton("Close");
		this.btnClose.setBounds(90, 60, 100, 30);
		this.btnClose.addActionListener(i -> f.dispose());
		f.add(this.l);
		f.add(this.btnClose);
		f.setSize(310, 150);
		f.setLayout(null);
		f.setVisible(true);
		f.setLocationRelativeTo(null);
		f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	}
}