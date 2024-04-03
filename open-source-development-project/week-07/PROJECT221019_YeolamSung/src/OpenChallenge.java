import java.awt.*;
import javax.swing.*;

class NorthPanel extends JPanel { //NORTH에 붙일 패널

  public NorthPanel() {
    setBackground(Color.DARK_GRAY);
    setLayout(new FlowLayout(FlowLayout.CENTER, 6, 6));
    JButton jb = new JButton("Open");
    add(jb);
    jb = new JButton("Read");
    add(jb);
    jb = new JButton("Close");
    add(jb);
  }
}

class CenterPanel extends JPanel {

  public CenterPanel() {
    setLayout(null);
    setBackground(Color.LIGHT_GRAY);
    JLabel label = new JLabel("Hello");
    label.setLocation(120, 20);
    label.setSize(30, 10);
    add(label);
    label = new JLabel("Love");
    label.setLocation(250, 150);
    label.setSize(30, 10);
    add(label);
    label = new JLabel("Java");
    label.setLocation(30, 180);
    label.setSize(30, 10);
    add(label);
  }
}

public class OpenChallenge extends JFrame {

  public OpenChallenge() {
    setTitle("Open Challenge 9");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    Container c = getContentPane();
    c.setLayout(new BorderLayout());
    NorthPanel np = new NorthPanel();
    c.add(np, BorderLayout.NORTH);
    CenterPanel cp = new CenterPanel();
    c.add(cp, BorderLayout.CENTER);
    setSize(400, 400);
    setVisible(true);
  }

  public static void main(String[] args) {
    new OpenChallenge();
  }
}
