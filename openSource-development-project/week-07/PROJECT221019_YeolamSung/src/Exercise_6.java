import java.awt.*;
import javax.swing.*;

public class Exercise_6 extends JFrame {

  public Exercise_6() {
    setTitle("Random Labels");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    Container c = getContentPane();
    c.setLayout(null);

    for (int i = 0; i < 20; i++) {
      JLabel j = new JLabel(Integer.toString(i));
      int x = (int) (Math.random() * 200) + 50;
      int y = (int) (Math.random() * 200) + 50;
      j.setLocation(x, y);
      j.setSize(10, 10);
      j.setOpaque(true);
      j.setBackground(Color.BLUE);
      c.add(j);
    }

    setSize(300, 300);
    setVisible(true);
  }

  public static void main(String[] args) {
    new Exercise_6();
  }
}
