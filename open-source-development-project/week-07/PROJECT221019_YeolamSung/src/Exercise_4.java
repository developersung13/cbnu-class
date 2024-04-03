import java.awt.*;
import javax.swing.*;

public class Exercise_4 extends JFrame {

  public Exercise_4() {
    setTitle("Ten Color Buttons Frame");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    Container c = getContentPane();
    c.setLayout(new GridLayout(1, 10));

    Color[] colors = new Color[] {
      Color.RED,
      Color.ORANGE,
      Color.YELLOW,
      Color.GREEN,
      Color.CYAN,
      Color.BLUE,
      Color.MAGENTA,
      Color.GRAY,
      Color.PINK,
      Color.LIGHT_GRAY,
    };

    for (int i = 0; i <= 9; i++) {
      JButton jb = new JButton(Integer.toString(i));
      jb.setBackground(colors[i]);
      c.add(jb);
    }
    setSize(450, 200);
    setVisible(true);
  }

  public static void main(String[] args) {
    new Exercise_4();
  }
}
