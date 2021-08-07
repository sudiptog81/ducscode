package pro.ghosh.sudipto.notepadClone;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

public class MenuListener implements ActionListener {
    Main m;

    MenuListener(Main m) {
        this.m = m;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == this.m.closeMenuItem) {
            int ch = JOptionPane.showConfirmDialog(null, "Are you sure you want to exit?");
            if (ch == 0) this.m.dispose();
        } else if (e.getSource() == this.m.saveMenuItem) {
            String fileName = "";
            try {
                fileName = JOptionPane.showInputDialog("Enter Filename");
                if (fileName == null) throw new IOException("Invalid Filename");
                FileWriter w = new FileWriter(fileName);
                BufferedWriter bw = new BufferedWriter(w);
                bw.write(this.m.textArea.getText());
                bw.close();
                w.close();
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            } finally {
                JOptionPane.showMessageDialog(null, "Saved to " + fileName,
                        "Save Successful", JOptionPane.INFORMATION_MESSAGE
                );
            }
        } else if (e.getSource() == this.m.openMenuItem) {
            String fileName = "";
            try {
                fileName = JOptionPane.showInputDialog("Enter Filename");
                if (fileName == null) throw new IOException("Invalid Filename");
                FileReader r = new FileReader(fileName);
                BufferedReader br = new BufferedReader(r);
                StringBuilder sb = new StringBuilder();
                String line = "";
                while ((line = br.readLine()) != null) {
                    sb.append(line).append('\n');
                }
                sb.deleteCharAt(sb.length() - 1);
                this.m.textArea.setText(sb.toString());
                this.m.refreshCounters();
                br.close();
                r.close();
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage(),
                        "Error", JOptionPane.ERROR_MESSAGE
                );
            }
        } else if (e.getSource() == this.m.aboutMenuItem) {
            new About();
        }
    }
}
