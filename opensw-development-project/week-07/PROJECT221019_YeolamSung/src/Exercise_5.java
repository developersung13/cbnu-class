import java.awt.*;
import javax.swing.*;

public class Exercise_5 extends JFrame {

  public Exercise_5() {
    setTitle("4x4 Color Frame");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    Container c = getContentPane();
    c.setLayout(new GridLayout(4, 4));
    float[] f = new float[] { 0, 0, 0 };

    for (int i = 0; i < 16; i++) {
      JLabel jl = new JLabel(Integer.toString(i));
      jl.setOpaque(true);
      for (int j = 0; j < 3; j++) {
        f[j] = (float) (Math.random());
      }
      Color bgColor = Color.getHSBColor(f[0], f[1], f[2]);
      c.add(jl).setBackground(bgColor);
    }

    setSize(450, 200);
    setVisible(true);
  }

  public static void main(String[] args) {
    new Exercise_5();
  }
}
